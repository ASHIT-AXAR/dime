/**************************************************************************\
 * 
 *  FILE: Table.h
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

#ifndef DIME_TABLE_H
#define DIME_TABLE_H

#include <dime/Base.h>
#include <dime/util/Array.h>

class dimeInput;
class dimeModel;
class dimeOutput;
class dimeTableEntry;
class dimeRecord;

class dimeTable : public dimeBase
{
public:
  dimeTable(dimeMemHandler * const memhandler);
  virtual ~dimeTable();
  
  bool read(dimeInput * const in);
  bool write(dimeOutput * const out);
  dimeTable *copy(dimeModel * const model) const;
  int typeId() const;
  int countRecords() const;
  int tableType() const;
  const char *tableName() const;
  
  int getNumTableEntries() const;
  dimeTableEntry *getTableEntry(const int idx);
  void insertTableEntry(dimeTableEntry * const tableEntry, const int idx = -1);
  void removeTableEntry(const int idx);

  int getNumTableRecords() const;
  dimeRecord *getTableRecord(const int idx);
  void insertTableRecord(dimeRecord * const record, const int idx = -1);
  void removeTableRecord(const int idx);

private:
  int16 maxEntries; // dummy variable read from file
  dimeArray <dimeTableEntry*> tableEntries;
  dimeArray <dimeRecord*> records;
  dimeMemHandler *memHandler;

}; // class dimeTable

#endif // ! DIME_TABLE_H
