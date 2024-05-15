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

#ifndef ROR2MMURL_H
#define ROR2MMURL_H

#include "dllimport.h"
#include <QList>
#include <QObject>
#include <QString>

/**
 * @brief represents a ror2mm:// url
 * @todo the game name encoded into the url is not interpreted
 **/
class QDLLEXPORT ROR2MMUrl : public QObject
{
  Q_OBJECT

public:
  /**
   * @brief constructor
   *
   * @param url url following the nxm-protocol
   **/
  ROR2MMUrl(const QString& url);

  /**
   * @return name of the game
   */
  QString game() const { return m_Game; }

  int modId() const { return m_ModId; }

  int fileId() const { return m_FileId; }

  QString modAuthor() const { return m_ModAuthor; }

  QString modName() const { return m_ModName; }

  QString version() const { return m_Version; }

  QString downloadUrl() const { return m_DownloadURL; }

  QString fileName() const { return m_FileName; }

private:
  QString m_Game;
  int m_ModId;
  int m_FileId;

  QString m_ModAuthor;
  QString m_ModName;
  QString m_Version;
  QString m_DownloadURL;
  QString m_FileName;
};

#endif  // ROR2MMURL
