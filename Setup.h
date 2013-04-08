#ifndef SETUP_H
#define	SETUP_H

class Setup {
public:
    Setup();
    int getIterations();
    int getPopulation();
    int getConnectionsLimit();
    double getInvTemperature();
    double getLambda();
    double getAlpha();
    double getXm();
    unsigned int getSeed();
private:
    const int iterations; /* number of iterations */
    const int population; /* population count */
    const int connections_limit; /* max number of friendships */
    const double inverse_temperature;  /* statistical parameter */
    const double lambda; /* statistical parameter */
    const double alpha; /* Pareto distribution shape parameter */
    const double x_m; /* Pareto distribution scale (min) parameter */
    const unsigned int seed; /* prng seed, variable over runs */
    boost::random::mt19937 prng;
};

#endif	/* SETUP_H */
