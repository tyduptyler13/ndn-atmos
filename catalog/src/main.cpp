/** NDN-Atmos: Cataloging Service for distributed data originally developed
 *  for atmospheric science data
 *  Copyright (C) 2015 Colorado State University
 *
 *  NDN-Atmos is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  NDN-Atmos is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with NDN-Atmos.  If not, see <http://www.gnu.org/licenses/>.
**/

#include "catalog/catalog.hpp"
#include "util/mysql-util.hpp"

#include <ChronoSync/socket.hpp>

#include <ndn-cxx/data.hpp>
#include <ndn-cxx/face.hpp>
#include <ndn-cxx/interest.hpp>
#include <ndn-cxx/name.hpp>
#include <ndn-cxx/security/key-chain.hpp>

#include "mysql/mysql.h"

#include <memory>

int main()
{
  std::shared_ptr<chronosync::Socket> socket; // use ChronoSync
  std::shared_ptr<ndn::Face> face(new ndn::Face());
  std::shared_ptr<ndn::KeyChain> keyChain(new ndn::KeyChain());

  // This should be unique to each instance
  ndn::Name aName("/catalog/myUniqueName");

  atmos::util::ConnectionDetails mysqlID("atmos-den.es.net", "testuser", "test623", "testdb");
  std::shared_ptr<MYSQL> conn;
  conn = atmos::util::MySQLConnectionSetup(mysqlID);

  atmos::catalog::Catalog<MYSQL> catalog(face, keyChain, conn, aName);
  face->processEvents();

  return 0;
}
