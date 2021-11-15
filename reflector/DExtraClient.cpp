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

#include "Main.h"
#include "DExtraClient.h"


////////////////////////////////////////////////////////////////////////////////////////
// constructors

CDextraClient::CDextraClient()
{
	m_ProtRev = 0;
}

CDextraClient::CDextraClient(const CCallsign &callsign, const CIp &ip, char reflectorModule, int protRev)
	: CClient(callsign, ip, reflectorModule)
{
	m_ProtRev = protRev;
}

CDextraClient::CDextraClient(const CDextraClient &client)
	: CClient(client)
{
	m_ProtRev = client.m_ProtRev;
}

////////////////////////////////////////////////////////////////////////////////////////
// status

bool CDextraClient::IsAlive(void) const
{
	return (m_LastKeepaliveTime.time() < DEXTRA_KEEPALIVE_TIMEOUT);
}
