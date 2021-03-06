/**
 *  Copyright (C) 2011
 *  University of Rochester Department of Computer Science
 *    and
 *  Lehigh University Department of Computer Science and Engineering
 *
 * License: Modified BSD
 *          Please see the file LICENSE.RSTM for licensing information
 */

#ifndef BMCONFIG_HPP__
#define BMCONFIG_HPP__

#include <stdint.h>
#include "ksnap.h"
#include <iostream>

/**
 * Standard benchmark configuration globals
 */
struct Config
{
  /*** THESE GET WRITTEN EARLY ***/
  std::string bmname;
  uint32_t    duration;               // in seconds
  uint32_t    execute;                // in transactions
  uint32_t    threads;                // number of threads
  uint32_t    nops_after_tx;          // self-explanatory
  uint32_t    elements;               // elements in data structure
  uint32_t    lookpct;                // lookup percent
  uint32_t    inspct;                 // insert percent
  uint32_t    qrypct;                 // query percent
  uint32_t    threadq;                // threads performing long running queries
  uint32_t    sets;                   // number of sets to create
  uint32_t    ops;                    // operations per transaction
  bool    print_query_time;

  bool useconversion;
  /*** THESE GET UPDATED LATER ***/
  volatile uint64_t time;
  volatile bool     running;
  volatile uint64_t txcount;
  
  Config();
};

extern Config CFG;

/** BENCHMARKS IMPLEMENT THE FOLLOWING FUNCTIONS */

void thread_init();

/*** Initialize the counter */
void bench_init();

/*** Run a bunch of increment transactions */
void bench_test(uintptr_t, uint32_t*, conv_seg *);

/*** Ensure the final state of the benchmark satisfies all invariants */
bool bench_verify(conv_seg *);

/*** arg reparser */
void bench_reparse();

#endif // BMCONFIG_HPP__
