/*
Copyright (C) 2012 Sebastian Herbord. All rights reserved.

This file is part of Mod Organizer.

Mod Organizer is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Mod Organizer is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Mod Organizer.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ror2mmurl.h"
#include "utility.h"
#include <QList>
#include <QRegularExpression>
#include <QString>
#include <QUrl>
#include <QUrlQuery>
#include <QHash>

ROR2MMUrl::ROR2MMUrl(const QString& url)
{
  QUrl ror2mm(url);
  QUrlQuery query(ror2mm);
  QRegularExpression exp("ror2mm://v1/install/thunderstore\\.io/([^/]+)/([^/]+)/([^/]+)/$", QRegularExpression::CaseInsensitiveOption);

  auto match = exp.match(url);
  if (!match.hasMatch()) {
    throw MOBase::InvalidROR2MMLinkException(url);
  }

  // TODO: use get request to get the community id with thunderstore api
  m_Game        = QString("valheim");  // ror2mm.host();
  m_ModId       = qHash(match.captured(1) + match.captured(2));
  m_FileId      = qHash(m_ModAuthor + "_" + m_ModName + "-" + m_Version + ".zip");
  m_ModAuthor   = match.captured(1);   // ModAuthor
  m_ModName     = match.captured(2);   // ModName
  m_Version     = match.captured(3);  // ModVersion
  m_DownloadURL = QString("https://thunderstore.io/package/download/") + m_ModAuthor + "/" + m_ModName + "/" + m_Version;
  m_FileName = m_ModAuthor + "_" + m_ModName + "-" + m_Version + ".zip";
}
