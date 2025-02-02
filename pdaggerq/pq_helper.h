//
// pdaggerq - A code for bringing strings of creation / annihilation operators to normal order.
// Filename: pq_helper.h
// Copyright (C) 2020 A. Eugene DePrince III
//
// Author: A. Eugene DePrince III <adeprince@fsu.edu>
// Maintainer: DePrince group
//
// This file is part of the pdaggerq package.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#ifndef PQ_HELPER_H
#define PQ_HELPER_H

#include "pq.h"
#include "data.h"

namespace pdaggerq {

class pq_helper {

  private:

    /// list of strings of operators
    std::vector< std::shared_ptr<pq> > ordered;

    /// strings, tensors, etc.
    std::shared_ptr<StringData> data;

    /// vacuum (fermi or true)
    std::string vacuum;

    /// bra (vacuum, singles, or doubles)
    std::string bra;

    /// ket (vacuum, singles, or doubles)
    std::string ket;

    /// print level
    int print_level;

    /// operators to apply to the left of any operator products we add
    std::vector<std::string> left_operators;

    /// operators to apply to the right of any operator products we add
    std::vector<std::string> right_operators;

    /// do operators entering a similarity transformation commute?
    bool cluster_operators_commute_;

  public:

    /// constructor
    pq_helper(std::string vacuum_type);

    /// destructor
    ~pq_helper();

    /// set operators to apply to the left of any operator products we add
    void set_left_operators(std::vector<std::string> in);

    /// set operators to apply to the right of any operator products we add
    void set_right_operators(std::vector<std::string> in);

    /// when bringing to normal order, does the bra involve any operators?
    void set_bra(std::string bra_type);

    /// when bringing to normal order, does the ket involve any operators?
    void set_ket(std::string ket_type);

    /// set print level (default zero)
    void set_print_level(int level);

    /// set a string of creation / annihilation operators
    void set_string(std::vector<std::string> in);

    /// set labels for a one- or two-body tensor
    void set_tensor(std::vector<std::string> in, std::string tensor_type);

    /// set labels for t1, t2, or t3 amplitudes
    void set_t_amplitudes(std::vector<std::string> in);

    /// set labels for u1 or u2 amplitudes
    void set_u_amplitudes(std::vector<std::string> in);

    /// set labels for m1 or m2 amplitudes
    void set_m_amplitudes(std::vector<std::string> in);

    /// set labels for s1 or s2 amplitudes
    void set_s_amplitudes(std::vector<std::string> in);

    /// set labels for l1 or l2 amplitudes
    void set_left_amplitudes(std::vector<std::string> in);

    /// set labels for r1 or r2 amplitudes
    void set_right_amplitudes(std::vector<std::string> in);

    /// set a numerical factor
    void set_factor(double in);

    /// add new completed string / tensor / amplitudes / factor
    void add_new_string();

    /// add new completed string / tensor / amplitudes / factor (assuming normal order is definied relative to the true vacuum
    void add_new_string_true_vacuum();

    /// add new completed string / tensor / amplitudes / factor (assuming normal order is definied relative to the fermi vacuum
    void add_new_string_fermi_vacuum();

    /// add new complete string as a product of operators (i.e., {'h(pq)','t1(ai)'} )
    void add_operator_product(double factor, std::vector<std::string> in);

    /// add similarity-transformed operator expansion of an operator
    void add_st_operator(double factor, std::vector<std::string> targets, std::vector<std::string> ops);

    /// add commutator of two operators
    void add_commutator(double factor, std::vector<std::string> op0,
                                       std::vector<std::string> op1);

    /// add double commutator involving three operators
    void add_double_commutator(double factor, std::vector<std::string> op0,
                                              std::vector<std::string> op1,
                                              std::vector<std::string> op2);

    /// add triple commutator involving four operators
    void add_triple_commutator(double factor, std::vector<std::string> op0,
                                              std::vector<std::string> op1,
                                              std::vector<std::string> op2,
                                              std::vector<std::string> op3);

    /// add quadruple commutator involving five operators
    void add_quadruple_commutator(double factor, std::vector<std::string> op0,
                                                 std::vector<std::string> op1,
                                                 std::vector<std::string> op2,
                                                 std::vector<std::string> op3,
                                                 std::vector<std::string> op4);


    /// cancel terms, if possible
    void simplify();

    /// clear strings
    void clear();

    /// print strings
    void print();

    /// get list of strings 
    std::vector<std::vector<std::string> > strings();

    /// print fully-contracted strings
    void print_fully_contracted();

    /// get list of fully-contracted strings
    std::vector<std::vector<std::string> > fully_contracted_strings();

    /// print one-body strings
    void print_one_body();

    /// print two-body strings
    void print_two_body();

    /// do operators entering similarity transformation commute? default true
    void set_cluster_operators_commute(bool cluster_operators_commute);
};

}

#endif
