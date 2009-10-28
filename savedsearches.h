/*
 * Copyright (C) 2009 Nicolas Bonnefon and other contributors
 *
 * This file is part of LogCrawler.
 *
 * LogCrawler is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LogCrawler is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LogCrawler.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SAVEDSEARCHES_H
#define SAVEDSEARCHES_H

#include <QString>
#include <QStringList>
#include <QMetaType>

// Keeps track of the previously used searches and allows the application
// to retrieve them.
class SavedSearches
{
  public:
    // Creates an empty set of saved searches
    SavedSearches();

    // Adds the passed search to the list of recently used searches
    void addRecent( const QString& text );

    // Returns a list of recent searches (newer first)
    QStringList recentSearches() const;

    // Operators for serialization
    friend QDataStream& operator<<( QDataStream& out, const SavedSearches& object );
    friend QDataStream& operator>>( QDataStream& in, SavedSearches& object );

  private:
    static const int maxNumberOfRecentSearches = 20;

    QStringList savedSearches_;
};

Q_DECLARE_METATYPE(SavedSearches)

#endif
