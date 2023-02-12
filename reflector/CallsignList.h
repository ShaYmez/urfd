//  Copyright © 2015 Jean-Luc Deltombe (LX3JL). All rights reserved.

// urfd -- The universal reflector
// Copyright © 2021 Thomas A. Early N7TAE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include <list>
#include <mutex>

#include "CallsignListItem.h"

////////////////////////////////////////////////////////////////////////////////////////
// class

class CCallsignList
{
public:
	// constructor
	CCallsignList();

	// locks
	void Lock(void)                        { m_Mutex.lock(); }
	void Unlock(void)                      { m_Mutex.unlock(); }

	// file io
	virtual bool LoadFromFile(const std::string &str);
	bool ReloadFromFile(void);
	bool NeedReload(void);

	// compare
	bool IsCallsignListedWithWildcard(const CCallsign &) const;
	bool IsCallsignListedWithWildcard(const CCallsign &, char) const;
	bool IsCallsignListed(const CCallsign &, char) const;
	bool IsCallsignListed(const CCallsign &, char*) const;

	// pass-thru
	bool empty() const                             { return m_Callsigns.empty(); }
	std::list<CCallsignListItem>::iterator begin() { return m_Callsigns.begin(); }
	std::list<CCallsignListItem>::iterator end()   { return m_Callsigns.end(); }

	// find
	CCallsignListItem *FindListItem(const CCallsign &);

protected:
	bool GetLastModTime(time_t *);
	char *TrimWhiteSpaces(char *);

	// data
	std::mutex      m_Mutex;
	std::string     m_Filename;
	time_t          m_LastModTime;
	std::list<CCallsignListItem> m_Callsigns;
};
