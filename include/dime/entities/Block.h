/**************************************************************************\
 * 
 *  FILE: Block.h
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

#ifndef DIME_BLOCK_H
#define DIME_BLOCK_H

#include <dime/Basic.h>
#include <dime/entities/Entity.h>
#include <dime/util/Linear.h>

class dimeInput;
class dimeMemHandler;
class dimeModel;
class dimeOutput;

class dimeBlock : public dimeEntity
{
  friend class dimeBlocksSection;
  friend class dimeEntitiesSection;
  friend class dimeInsert;
  friend class dimeModel;
  
public:
  dimeBlock(dimeMemHandler * const memhandler);
  virtual ~dimeBlock();

  const dimeVec3f &getBasePoint() const;
  void setBasePoint(const dimeVec3f &v);
  int getNumEntities() const;
  dimeEntity *getEntity(const int idx);
  void insertEntity(dimeEntity * const entity, const int idx = -1);
  void removeEntity(const int idx, const bool deleteIt = true);
  void fitEntities();

  const char *getName() const;
  void setName(const char * const name);
 
  dimeEntity *copy(dimeModel * const model) const;
  virtual bool getRecord(const int groupcode,
			 dimeParam &param,
			 const int index = 0) const;
  virtual const char *getEntityName() const;

  virtual bool read(dimeInput * const in);
  virtual bool write(dimeOutput * const out);
  virtual int typeId() const;
  virtual int countRecords() const;

protected:  
  virtual bool handleRecord(const int groupcode, 
                            const dimeParam & param,
			    dimeMemHandler * const memhandler);
  
  virtual void fixReferences(dimeModel * const model);
  virtual bool traverse(const dimeState * const state, 
                        dimeCallback callback,
                        void *userdata);
  
private:
  int16 flags;
  const char *name;
  dimeVec3f basePoint;
  dimeArray <dimeEntity*> entities;
  dimeEntity *endblock;
  dimeMemHandler *memHandler;

}; // class dimeBlock

inline const dimeVec3f &
dimeBlock::getBasePoint() const 
{
  return this->basePoint;
}

inline void 
dimeBlock::setBasePoint(const dimeVec3f &v)
{
  this->basePoint = v;
}

inline int 
dimeBlock::getNumEntities() const
{
  return this->entities.count();
}

inline dimeEntity *
dimeBlock::getEntity(const int idx)
{
  assert(idx >= 0 && idx < this->entities.count());
  return this->entities[idx];
}

inline const char *
dimeBlock::getName() const
{
  return this->name;
}

inline void 
dimeBlock::setName(const char * const name)
{
  this->name = name;
}

#endif // ! DIME_BLOCK_H
