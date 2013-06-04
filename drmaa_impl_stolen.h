#ifndef DRMAA_STOLEN
#define DRMAA_STOLEN

/*
 * This file contains fragments taken from : https://github.com/adaptivecomputing/torque/blob/master/src/drmaa/src/drmaa_impl.h
 *
 * Those fragments are covered under the GPL, so I must include the GPL statement here.
 */

/* $Id: drmaa_impl.h,v 1.9 2006/09/08 18:18:08 ciesnik Exp $ */
/*
 * * DRMAA library for Torque/PBS
 * * Copyright (C) 2006 Poznan Supercomputing and Networking Center
 * * DSP team <dsp-devel@hedera.man.poznan.pl>
 * *
 * * This library is free software; you can redistribute it and/or
 * * modify it under the terms of the GNU Lesser General Public
 * * License as published by the Free Software Foundation; either
 * * version 2.1 of the License, or (at your option) any later version.
 * *
 * * This library is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * * Lesser General Public License for more details.
 * *
 * * You should have received a copy of the GNU Lesser General Public
 * * License along with this library; if not, write to the Free Software
 * * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 * */



#include <drmaa.h>

typedef struct drmaa_session_s drmaa_session_t;

typedef struct drmaa_job_s drmaa_job_t;

/** Mutex for accessing @ref drmaa_session global variable. */
extern pthread_mutex_t drmaa_session_mutex;
extern drmaa_session_t *drmaa_session;


/** DRMAA session data. */

struct drmaa_session_s
  {
  int pbs_conn; /**< PBS connection (or -1). */
  char *contact; /**< Contact to PBS server -- `host[:port]'. */
  drmaa_job_template_t *jt_list; /**< Cyclic list (with sentinel) of job
templates created in this DRMAA session. */
  drmaa_job_t **job_hashtab; /**< Hash table of jobs
which have to be remembered in DRMAA
session (was submitted in this
session and its status was not removed). */
  int next_time_label; /**< Will be assigned to next submitted job. */
  pthread_mutex_t conn_mutex; /**< Mutex for PBS connection. */
  pthread_mutex_t jobs_mutex; /**< Mutex for #jt_list, #job_list
and #next_time_label. */
  };

struct drmaa_job_template_s
  {
  drmaa_session_t *session; /**< DRMAA session in which job template was created. */
  drmaa_job_template_t *prev; /**< Previous job template in list. */
  drmaa_job_template_t *next; /**< Next job template in list. */
  void **attrib; /**< Table of DRMAA attributes.
It is filled with N_DRMAA_ATTRIBS values which are either @c NULL
(attribute not set) or string (scalar attribute) or @c NULL terminated
array of strings (vector attribute). */
  pthread_mutex_t mutex; /**< Mutex for accessing job attributes. */
  };


struct drmaa_attr_names_s
  {
  char **list, **iter;
  };

struct drmaa_attr_values_s
  {
  char **list, **iter;
  };

struct drmaa_job_ids_s
  {
  char **list, **iter;
  };

#endif
