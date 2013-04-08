#ifndef NETWORK_H
#define	NETWORK_H

class Network {
public:
    Network(int n);
    void switchParty(int my_index, int new_party_index);
    void addFriend(int my_index, int friend_index);
    int getParty(int my_index);
    std::set<int> getFriends(int my_index);
    Network cluster(Setup setup, System system, unsigned int prng_seed);
    Network plod(Setup setup);
private:
    std::vector<Person> nodes;
};

typedef std::vector<Network> Bundle;

#endif	/* GRAPH_H */

