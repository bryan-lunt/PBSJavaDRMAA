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
  };

struct drmaa_job_template_s
  {
  };


struct drmaa_attr_names_s
  {
  };

struct drmaa_attr_values_s
  {
  };

struct drmaa_job_ids_s
  {
  };

#endif
