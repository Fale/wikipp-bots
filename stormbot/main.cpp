/*
    Copyright (C) 2008, 2009  Fabio Alessandro Locati - fabiolocati@gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MOVEBOT
#define MOVEBOT

#define WIKIMEDIA

#include <wiki++/libs/prgdata.h>
#include <wiki++/wiki/login.h>
#include <wiki++/extended/storm.h>

int main()
{
  // Get the basic configurations of the program
  // TODO: make the "frequence" parameter useable from bash line instead of from config file
  // TODO: make the "page" parameter useable from bash line instead of from config file
  // TODO: in this way it will be enought call the same program with different commands to make  it work
  // TODO: in the same wiki with different pages and different frequences
  std::string user( wikipp::libs::prgdata::getUsername() );
  std::string pass( wikipp::libs::prgdata::getPassword() );
  std::string proj( wikipp::libs::prgdata::getProject() );
  std::string page( wikipp::libs::prgdata::getPage() );
  std::string tizo( wikipp::libs::prgdata::getTimeZone() );
  std::string lang( wikipp::libs::prgdata::getLanguage() );
  std::string freq( wikipp::libs::prgdata::getVariable( "frequence" ) ); //Available options: initial, hourly, daily, weekly, monthly, yearly

  // Login in the wiki
  wikipp::wiki::login::wikiLogin( proj, user, pass );

  // Start the movePage procedure
  wikipp::extended::storm storm;
  storm.setLang( lang );
  storm.setTZ( tizo );
  storm.setFreq( freq );
  storm.movePage( proj, page );

  return 0;
}

#endif
