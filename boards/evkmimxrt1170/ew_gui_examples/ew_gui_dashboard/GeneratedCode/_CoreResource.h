/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software is delivered "as is" and shows the usage of other software 
* components. It is provided as an example software which is intended to be 
* modified and extended according to particular requirements.
* 
* TARA Systems hereby disclaims all warranties and conditions with regard to the
* software, including all implied warranties and conditions of merchantability 
* and non-infringement of any third party IPR or other rights which may result 
* from the use or the inability to use the software.
*
* This file was generated automatically by Embedded Wizard Studio.
*
* Please do not make any modifications of this file! The modifications are lost
* when the file is generated again by Embedded Wizard Studio!
*
* Version  : 10.0
* Date     : 17.02.2021  8:00:50
* Profile  : iMX_RT
* Platform : NXP.iMX_RT_VGLite.RGB565
*
*******************************************************************************/

#ifndef _CoreResource_H
#define _CoreResource_H

#ifdef __cplusplus
  extern "C"
  {
#endif

#include "ewrte.h"
#if EW_RTE_VERSION != 0x000A0000
  #error Wrong version of Embedded Wizard Runtime Environment.
#endif

#include "ewgfx.h"
#if EW_GFX_VERSION != 0x000A0000
  #error Wrong version of Embedded Wizard Graphics Engine.
#endif

/* Forward declaration of the class Core::Resource */
#ifndef _CoreResource_
  EW_DECLARE_CLASS( CoreResource )
#define _CoreResource_
#endif


/* Deklaration of class : 'Core::Resource' */
EW_DEFINE_FIELDS( CoreResource, XObject )
  EW_VARIABLE( resource,        XHandle )
EW_END_OF_FIELDS( CoreResource )

/* Virtual Method Table (VMT) for the class : 'Core::Resource' */
EW_DEFINE_METHODS( CoreResource, XObject )
EW_END_OF_METHODS( CoreResource )

/* 'C' function for method : 'Core::Resource.Done()' */
void CoreResource_Done( CoreResource _this );

/* 'C' function for method : 'Core::Resource.Init()' */
void CoreResource_Init( CoreResource _this, XHandle aArg );

#ifdef __cplusplus
  }
#endif

#endif /* _CoreResource_H */

/* Embedded Wizard */