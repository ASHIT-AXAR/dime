/**************************************************************************\
 * 
 *  FILE: RecordHolder.h
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

#ifndef DIME_RECORDHOLDER_H
#define DIME_RECORDHOLDER_H

#include <dime/Base.h>

class dimeInput;
class dimeMemHandler;
class dimeOutput;
class dimeRecord;

class dimeRecordHolder : public dimeBase
{
public:
  dimeRecordHolder(const int separator);
  virtual ~dimeRecordHolder();

  void setRecord(const int groupcode, const dimeParam &value, 
		 dimeMemHandler * const memhandler = NULL);
  void setRecords(const int * const groupcodes,
		  const dimeParam * const params,
		  const int numrecords,
		  dimeMemHandler * const memhandler = NULL);
  virtual bool getRecord(const int groupcode,
			 dimeParam &param,
			 const int index = 0) const;
  
  virtual bool read(dimeInput * const in);
  virtual bool write(dimeOutput * const out);
  virtual bool isOfType(const int thetypeid) const;
  virtual int countRecords() const;

  dimeRecord *findRecord(const int groupcode);

protected:
  virtual bool handleRecord(const int groupcode,
			    const dimeParam &param,
			    dimeMemHandler * const memhandler);
  
  bool copyRecords(dimeRecordHolder * const rh, 
		   dimeMemHandler * const memhandler) const;
  
protected:
  dimeRecord **records;
  int numRecords;
  // int separator; // not needed ?

}; // class dimeRecordHolder

#endif // ! DIME_RECORDHOLDER_H
