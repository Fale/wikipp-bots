/*
    Copyright (C) 2008, 2009 Fabio Alessandro Locati - fabiolocati@gmail.com

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

#ifndef INDEXBOT
#define INDEXBOT

#include <wiki++/libs/prgdata.h>
#include <wiki++/wiki/login.h>
#include <wiki++/wiki/write.h>
#include <wiki++/extended/index.h>
#include <wiki++/libs/dati.h>

void print(std::string url, std::string page, std::string tz)
{
  std::string text;
  std::stringstream sstr;
  std::string INDEX[22][3];

  INDEX[0][0] = "USA";
  INDEX[0][1] = "Dow Jones Industrial Average";
  INDEX[0][2] = "^DJI";
  INDEX[1][0] = "USA";
  INDEX[1][1] = "NASDAQ 100";
  INDEX[1][2] = "^NDX";
  INDEX[2][0] = "USA";
  INDEX[2][1] = "S&P 500";
  INDEX[2][2] = "^GSPC";
  INDEX[3][0] = "CAN";
  INDEX[3][1] = "S&P TSX";
  INDEX[3][2] = "^GSPTSE";
  INDEX[4][0] = "MEX";
  INDEX[4][1] = "IPC";
  INDEX[4][2] = "^MXX";
  INDEX[5][0] = "ARG";
  INDEX[5][1] = "Buenos Aires Merval";
  INDEX[5][2] = "^MERV";
  INDEX[6][0] = "BRA";
  INDEX[6][1] = "BOVESPA";
  INDEX[6][2] = "IBOVESPA.SA";

  INDEX[7][0] = "UK";
  INDEX[7][1] = "FTSE 100";
  INDEX[7][2] = "^FTSE";
  INDEX[8][0] = "GER";
  INDEX[8][1] = "DAX";
  INDEX[8][2] = "^GDAXI";
  INDEX[9][0] = "FRA";
  INDEX[9][1] = "CAC 40";
  INDEX[9][2] = "^FCHI";
  INDEX[10][0] = "SUI";
  INDEX[10][1] = "SMI";
  INDEX[10][2] = "^SSMI";
  INDEX[11][0] = "NED";
  INDEX[11][1] = "AEX";
  INDEX[11][2] = "^AEX";
  INDEX[11][0] = "BEL";
  INDEX[11][1] = "Euronext BEL-20";
  INDEX[11][2] = "^BFX";
  INDEX[12][0] = "ESP";
  INDEX[12][1] = "IGBN";
  INDEX[12][2] = "^SMSI";
  INDEX[13][0] = "ITA";
  INDEX[13][1] = "S&P/MIB";
  INDEX[13][2] = "^SPMIB";
  INDEX[14][0] = "ITA";
  INDEX[14][1] = "MIBTel";
  INDEX[14][2] = "^MIBTEL";
  INDEX[15][0] = "ITA";
  INDEX[15][1] = "MIDEX";
  INDEX[15][2] = "^MIDEX";
  INDEX[16][0] = "ITA";
  INDEX[16][1] = "All Stars";
  INDEX[16][2] = "^ALLST";
  INDEX[17][0] = "ITA";
  INDEX[17][1] = "MIB 30";
  INDEX[17][2] = "^MIB30";

  INDEX[18][0] = "AUS";
  INDEX[18][1] = "ALL ORDINARIES IDX";
  INDEX[18][2] = "^AORD";
  INDEX[19][0] = "JPN";
  INDEX[19][1] = "NIKKEI 225";
  INDEX[19][2] = "^N225";
  INDEX[20][0] = "HKG";
  INDEX[20][1] = "HANG SENG";
  INDEX[20][2] = "^HSI";
  INDEX[21][0] = "CHN";
  INDEX[21][1] = "SSE Composite Index";
  INDEX[21][2] = "000001.SS";

  int c = 0;
  sstr << "{| border='1' cellpadding='3' cellspacing='0' style='text-align:center; margin-top:.5em; margin-bottom:.5em; border:1px solid #bbb; border-collapse:collapse;'" << std::endl;
  sstr << "|-bgcolor=#dddddd" << std::endl;
  sstr << "!width=12%|Nazione" << std::endl;
  sstr << "!width=12%|Indice" << std::endl;
  sstr << "!width=12%|Valore" << std::endl;
  sstr << "!width=12%|Variazione" << std::endl;
  sstr << "!width=12%|Variazione %" << std::endl;

  while(c < 22)
  {
    if (c == 0)
      sstr << "|- colspan=5 bgcolor=#dddddd" << std::endl << "|colspan=5|'''''America'''''" << std::endl;
    if (c == 7)
      sstr << "|- colspan=5 bgcolor=#dddddd" << std::endl << "|colspan=5|'''''Europa'''''" << std::endl;
    if (c == 18)
      sstr << "|- colspan=5 bgcolor=#dddddd" << std::endl << "|colspan=5|'''''Asia e Oceania'''''" << std::endl;
    if ( (c%2)==0 )
      sstr << "|-" << std::endl;
    else
      sstr << "|-bgcolor=#f1f1f1" << std::endl;
    sstr << "|{{" << INDEX[c][0] << "}}" << std::endl;
    sstr << "|" << INDEX[c][1] << std::endl;
    sstr << wikipp::extended::index::yahoo(INDEX[c][2]);
    c++;
  }

  sstr << "|}" << std::endl;
  std::vector<int> time = wikipp::libs::dati::dateTime();
  sstr << "Aggiornato alle " << time[2] << ":" << time[1] << ":" << time[0];
  sstr << " del " << time[3] << "/" << time[4] << "/" << time[5] << "." << std::endl << std::endl;
  sstr << "I dati potrebbero essere ritardati di 15 o 20 minuti.";
  text = sstr.str();
  //wikipp::wiki::write::writePage(url,page,text,"IndexBot: Aggiorno i valori degli indici");
  std::cout << text;
}

int main()
  {
    std::string user( wikipp::libs::prgdata::getUsername() );
    std::string pass( wikipp::libs::prgdata::getPassword() );
    std::string proj( wikipp::libs::prgdata::getProject() );
    std::string page( wikipp::libs::prgdata::getPage() );
    std::string tizo( wikipp::libs::prgdata::getTimeZone() );

    wikipp::wiki::login::wikiLogin(proj, user, pass);
    print(proj, page, tizo);

    return 0;
  }

#endif