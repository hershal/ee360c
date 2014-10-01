/*! MWMCM Results Wrapper Header */

#ifndef MWMCM_WRAPPER_H
#define MWMCM_WRAPPER_H

#include <map>
#include <vector>
#include <string>

class mwmcm {
public:

    struct mwmcm_compare {
        auto operator() (const mwmcm &a, const mwmcm &b) const -> bool {

            /* const auto a_map = a.get_tactic_map(); */
            /* const auto b_map = b.get_tactic_map(); */
            /*  */
            /* /\* The sets of the tics in a and b *\/ */
            /* std::vector<int32_t> a_vec; */
            /* std::vector<int32_t> b_vec; */
            /*  */
            /* for (auto i=a_map.begin(); i!=a_map.end(); ++i) { */
            /*     a_vec.push_back(i->second); */
            /* } */
            /*  */
            /* for (auto i=b_map.begin(); i!=b_map.end(); ++i) { */
            /*     b_vec.push_back(i->second); */
            /* } */
            /*  */
            /* auto a_vec_it = a_vec.begin(); */
            /* auto b_vec_it = b_vec.begin(); */
            /*  */
            /* while (a_vec_it != a_vec.end() && b_vec_it != b_vec.end()) { */
            /*     if (*a_vec_it > *b_vec_it) { */
            /*         return true; */
            /*     } else if (*a_vec_it < *b_vec_it){ */
            /*         return false; */
            /*     } */
            /*     else { */
            /*         a_vec_it++; */
            /*         b_vec_it++; */
            /*     } */
            /* } */
            /* return false; */

            return a.to_string() < b.to_string();
        }
    };

    mwmcm();
    auto add_association(int32_t tic, int32_t tac, int32_t weight) -> void;

    auto get_weight() const -> const int32_t;
    auto get_cardinality() const -> const size_t;
    auto get_tictac_map() const -> const std::map<int32_t, int32_t>;
    auto get_tactic_map() const -> const std::map<int32_t, int32_t>;

    auto to_string() const -> const std::string;
    auto operator<(mwmcm other) const -> bool;
private:
    std::map<int32_t, int32_t> tactic_map;
    std::map<int32_t, int32_t> tictac_map;
    int32_t weight;
    size_t cardinality;
};

#endif  /* MWMCM_WRAPPER_H */
