/**************************************************************************\
 * 
 *  FILE: Base.h
 *
 *  This source file is part of DIME.
 *  Copyright (C) 1998-1999 by Systems In Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License, version 2, as
 *  published by the Free Software Foundation.  DO NOT MISTAKE THIS LICENSE
 *  FOR THE GNU LGPL LICENSE.
 *
 *  This library is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License (the accompanying file named COPYING) for more
 *  details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 **************************************************************************
 *
 *  If you need DIME for commercial purposes, you can contact Systems In
 *  Motion about acquiring a commercial license.
 *
 *  Systems In Motion                                   http://www.sim.no/
 *  Prof. Brochs gate 6                                       sales@sim.no
 *  N-7030 Trondheim                                   Voice: +47 22114160
 *  NORWAY                                               Fax: +47 67172912
 *
\**************************************************************************/

#ifndef DIME_BASE_H
#define DIME_BASE_H

#include <dime/Basic.h>
#include <stddef.h>  // for size_t

class dimeMemHandler;

class dimeBase
{
public:
  enum {
    dimeBaseType = 1,
    dimeRecordType,
    dimeStringRecordType,
    dimeFloatRecordType,
    dimeDoubleRecordType,
    dimeInt8RecordType,
    dimeInt16RecordType,
    dimeInt32RecordType,
    dimeHexRecordType,
    dimeRecordHolderType,
    dimeClassType,
    dimeUnknownClassType,
    dimeObjectType,
    dimeUnknownObjectType,
    dimeEntityType,
    dimeUnknownEntityType,
    dimePolylineType,
    dimeVertexType,
    dimeFaceEntityType,
    dimeExtrusionEntityType,
    dime3DFaceType,
    dimeSolidType,
    dimeTraceType,
    dimeLineType,
    dimePointType,
    dimeBlockType,
    dimeInsertType,
    dimeCircleType,
    dimeArcType,
    dimeLWPolylineType,
    dimeEllipseType,
    dimeSplineType,
    dimeSectionType,
    dimeUnknownSectionType,
    dimeEntitiesSectionType,
    dimeBlocksSectionType,
    dimeTablesSectionType,
    dimeHeaderSectionType,
    dimeClassesSectionType,
    dimeObjectsSectionType,
    dimeTableType,
    dimeTableEntryType,
    dimeUnknownTableType,
    dimeUCSTableType,
    dimeLayerTableType,

    // this should be last
    dimeLastTypeTag
  };

  virtual int typeId() const = 0;
  virtual bool isOfType(const int thetypeid) const;
public:
  void *operator new(size_t size, dimeMemHandler *memhandler = NULL, 
		     const int alignment = 4);

}; // class dimeBase

#endif // ! DIME_BASE_H
