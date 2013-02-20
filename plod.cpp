#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/uniform_01.hpp>
#include "def.h"

graph plod (int population, int connections, graph adjlist, double alpha, double xm, Setup setup){
    const gsl_rng_type * T;
    gsl_rng * generator;
    generator = gsl_rng_alloc (gsl_rng_mt19937);
    gsl_rng_set (generator, setup.seed1);
    std::vector<int> friendships;
    for (int i = 0; i < population; ++i) {
        double random_float = gsl_ran_pareto (generator, alpha, xm);
        int random_integer = (int)random_float;
        friendships.push_back(random_integer);
    }
    int acc_connections = std::accumulate(friendships.begin(),friendships.end(),0);
    std::cout << acc_connections << std::endl;
    int minimum = 0;
    if (acc_connections/2 >= connections) {
        minimum = connections;
    }
    if (acc_connections/2 < connections) {
        minimum = acc_connections;
    }
    boost::mt19937 rgen1;
    rgen1.seed(static_cast<unsigned int>(setup.seed2));
    boost::uniform_int<> rdist1(0, (population - 1));
    for (int i = 0; i < minimum; ++i) {
        bool condition = true;
        while (condition == true) {
            int k = rdist1(rgen1);
            int l = rdist1(rgen1);
            int sum = 0;
            for (int m = 0; m < population; ++m) {
                sum += friendships[m];
            }
            if (sum < 2) {
                condition = false;
            }
            int it = (adjlist[k]).friends.count(l);
            if (k != l && friendships[k] > 0 && friendships[l] > 0 && it == 0) {
                --friendships[k];
                --friendships[l];
                (adjlist[k]).friends.insert(l);
                (adjlist[l]).friends.insert(k);
                condition = false;
            }
        }
    }
    gsl_rng_free(generator);
    return adjlist;
}
