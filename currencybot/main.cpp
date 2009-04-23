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

#ifndef CURRENCYBOT
#define CURRENCYBOT

#include <wiki++/libs/prgdata.h>
#include <wiki++/wiki/login.h>
#include <wiki++/extended/currency.h>
#include <wiki++/wiki/write.h>


void a( std::string url, std::string page, std::string tz )
{
  std::stringstream sstr;
  wikipp::extended::currency get;
  sstr << "{| border='1' cellpadding='3' cellspacing='0' style='text-align:center; margin-top:.5em; margin-bottom:.5em; border:1px solid #bbb; border-collapse:collapse;'" << std::endl;
  sstr << "|-bgcolor=#dddddd" << std::endl;
  sstr << "!width=16%|Cambio" << std::endl;
  sstr << "!width=12%|[[" + page + "/USD|Dollaro USA]] ($)" << std::endl;
  sstr << "!width=12%|[[" + page + "/EUR|Euro]] (€)" << std::endl;
  sstr << "!width=12%|[[" + page + "/JPY|Yen]] (¥)" << std::endl;
  sstr << "!width=12%|[[" + page + "/CAD|Dollaro Canadese]] ($)" << std::endl;
  sstr << "!width=12%|[[" + page + "/GBP|Sterlina]] (£)" << std::endl;
  sstr << "!width=12%|[[" + page + "/AUD|Dollaro Australiano]] ($)" << std::endl;
  sstr << "!width=12%|[[" + page + "/CHF|Franco Svizzero]] (Fr.)" << std::endl;
  sstr << "|-" << std::endl;
  sstr << "!bgcolor=#dddddd|[[" + page + "/USD|Dollaro USA]] ($)" << std::endl;
  sstr << "|bgcolor=#eeeeee|" << std::endl;
  sstr << "|" + get.yahoo("USD","EUR") << std::endl;
  sstr << "|" + get.yahoo("USD","JPY") << std::endl;
  sstr << "|" + get.yahoo("USD","CAD") << std::endl;
  sstr << "|" + get.yahoo("USD","GBP") << std::endl;
  sstr << "|" + get.yahoo("USD","AUD") << std::endl;
  sstr << "|" + get.yahoo("USD","CHF") << std::endl;
  sstr << "|-" << std::endl;
  sstr << "!bgcolor=#dddddd|[[" + page + "/EUR|Euro]] (€)" << std::endl;
  sstr << "|" + get.yahoo("EUR","USD") << std::endl;
  sstr << "|bgcolor=#eeeeee|" << std::endl;
  sstr << "|" + get.yahoo("EUR","JPY") << std::endl;
  sstr << "|" + get.yahoo("EUR","CAD") << std::endl;
  sstr << "|" + get.yahoo("EUR","GBP") << std::endl;
  sstr << "|" + get.yahoo("EUR","AUD") << std::endl;
  sstr << "|" + get.yahoo("EUR","CHF") << std::endl;
  sstr << "|-" << std::endl;
  sstr << "!bgcolor=#dddddd|[[" + page + "/JPY|Yen]] (¥)" << std::endl;
  sstr << "|" + get.yahoo("JPY","USD") << std::endl;
  sstr << "|" + get.yahoo("JPY","EUR") << std::endl;
  sstr << "|bgcolor=#eeeeee|" << std::endl;
  sstr << "|" + get.yahoo("JPY","CAD") << std::endl;
  sstr << "|" + get.yahoo("JPY","GBP") << std::endl;
  sstr << "|" + get.yahoo("JPY","AUD") << std::endl;
  sstr << "|" + get.yahoo("JPY","CHF") << std::endl;
  sstr << "|-" << std::endl;
  sstr << "!bgcolor=#dddddd|[[" + page + "/CAD|Dollaro Canadese]] ($)" << std::endl;
  sstr << "|" + get.yahoo("CAD","USD") << std::endl;
  sstr << "|" + get.yahoo("CAD","EUR") << std::endl;
  sstr << "|" + get.yahoo("CAD","JPY") << std::endl;
  sstr << "|bgcolor=#eeeeee|" << std::endl;
  sstr << "|" + get.yahoo("CAD","GBP") << std::endl;
  sstr << "|" + get.yahoo("CAD","AUD") << std::endl;
  sstr << "|" + get.yahoo("CAD","CHF") << std::endl;
  sstr << "|-" << std::endl;
  sstr << "!bgcolor=#dddddd|[[" + page + "/GBP|Sterlina]] (£)" << std::endl;
  sstr << "|" + get.yahoo("GBP","USD") << std::endl;
  sstr << "|" + get.yahoo("GBP","EUR") << std::endl;
  sstr << "|" + get.yahoo("GBP","JPY") << std::endl;
  sstr << "|" + get.yahoo("GBP","CAD") << std::endl;
  sstr << "|bgcolor=#eeeeee|" << std::endl;
  sstr << "|" + get.yahoo("GBP","AUD") << std::endl;
  sstr << "|" + get.yahoo("GBP","CHF") << std::endl;
  sstr << "|-" << std::endl;
  sstr << "!bgcolor=#dddddd|[[" + page + "/AUD|Dollaro Australiano]] ($)" << std::endl;
  sstr << "|" + get.yahoo("AUD","USD") << std::endl;
  sstr << "|" + get.yahoo("AUD","EUR") << std::endl;
  sstr << "|" + get.yahoo("AUD","JPY") << std::endl;
  sstr << "|" + get.yahoo("AUD","CAD") << std::endl;
  sstr << "|" + get.yahoo("AUD","GBP") << std::endl;
  sstr << "|bgcolor=#eeeeee|" << std::endl;
  sstr << "|" + get.yahoo("AUD","CHF") << std::endl;
  sstr << "|-" << std::endl;
  sstr << "!bgcolor=#dddddd|[[" + page + "/CHF|Franco Svizzero]] (Fr.)" << std::endl;
  sstr << "|" + get.yahoo("CHF","USD") << std::endl;
  sstr << "|" + get.yahoo("CHF","EUR") << std::endl;
  sstr << "|" + get.yahoo("CHF","JPY") << std::endl;
  sstr << "|" + get.yahoo("CHF","CAD") << std::endl;
  sstr << "|" + get.yahoo("CHF","GBP") << std::endl;
  sstr << "|" + get.yahoo("CHF","AUD") << std::endl;
  sstr << "|bgcolor=#eeeeee|" << std::endl;
  sstr << "|}" << std::endl;
  std::vector<int> time = wikipp::libs::dati::dateTime();
  sstr << "Aggiornato alle " << time[2] << ":" << time[1] << ":" << time[0];
  sstr << " del " << time[3] << "/" << time[4] << "/" << time[5] << "." << std::endl << std::endl;
  sstr << "I dati potrebbero essere ritardati di 15 o 20 minuti.";
  std::string text( sstr.str() );
  wikipp::wiki::write::writePage( url, page, text, "CurrencyBot: Aggiorno i cambi delle monete" );
  get.savefile();
}

void b(std::string url, int intBc, std::string bc, std::string page, std::string tz)
{
  std::string CURTBP[7];
  CURTBP[0] = "USD";
  CURTBP[1] = "EUR";
  CURTBP[2] = "JPY";
  CURTBP[3] = "CAD";
  CURTBP[4] = "GBP";
  CURTBP[5] = "AUD";
  CURTBP[6] = "CHF";

  std::string CUR[75];
  CUR[0] = "AED";
  CUR[1] = "ALL";
  CUR[2] = "ARS";
  CUR[3] = "AUD";
  CUR[4] = "BBD";
  CUR[5] = "BDT";
  CUR[6] = "BGN";
  CUR[7] = "BHD";
  CUR[8] = "BMD";
  CUR[9] = "BRL";
  CUR[10] = "BSD";
  CUR[11] = "CAD";
  CUR[12] = "CHF";
  CUR[13] = "CLP";
  CUR[14] = "CNY";
  CUR[15] = "COP";
  CUR[16] = "CRC";
  CUR[17] = "CZK";
  CUR[18] = "DKK";
  CUR[19] = "DOP";
  CUR[20] = "DZD";
  CUR[21] = "EEK";
  CUR[22] = "EGP";
  CUR[23] = "EUR";
  CUR[24] = "FJD";
  CUR[25] = "GBP";
  CUR[26] = "HKD";
  CUR[27] = "HRK";
  CUR[28] = "HUF";
  CUR[29] = "IDR";
  CUR[30] = "ILS";
  CUR[31] = "INR";
  CUR[32] = "IQD";
  CUR[33] = "IRR";
  CUR[34] = "ISK";
  CUR[35] = "JMD";
  CUR[36] = "JOD";
  CUR[37] = "JPY";
  CUR[38] = "KES";
  CUR[39] = "KRW";
  CUR[40] = "KWD";
  CUR[41] = "LBP";
  CUR[42] = "LKR";
  CUR[43] = "MAD";
  CUR[44] = "MUR";
  CUR[45] = "MXN";
  CUR[46] = "MYR";
  CUR[47] = "NOK";
  CUR[48] = "NZD";
  CUR[49] = "OMR";
  CUR[50] = "PEN";
  CUR[51] = "PHP";
  CUR[52] = "PKR";
  CUR[53] = "PLN";
  CUR[54] = "QAR";
  CUR[55] = "RON";
  CUR[56] = "RUB";
  CUR[57] = "SAR";
  CUR[58] = "SEK";
  CUR[59] = "SGD";
  CUR[60] = "SKK";
  CUR[61] = "THB";
  CUR[62] = "TND";
  CUR[63] = "TRY";
  CUR[64] = "TTD";
  CUR[65] = "TWD";
  CUR[66] = "USD";
  CUR[67] = "VEF";
  CUR[68] = "VND";
  CUR[69] = "XAF";
  CUR[70] = "XCD";
  CUR[71] = "XOF";
  CUR[72] = "XPF";
  CUR[73] = "ZAR";
  CUR[74] = "ZMK";

  std::string CURRENCY[75][3];
  CURRENCY[0][0] = "Flag_of_the_United_Arab_Emirates.svg";
  CURRENCY[0][1] = "Emirati Arabi Uniti";
  CURRENCY[0][2] = "Dirham degli Emirati Arabi Uniti";
  CURRENCY[1][0] = "Flag_of_Albania.svg";
  CURRENCY[1][1] = "Albania";
  CURRENCY[1][2] = "Lek";
  CURRENCY[2][0] = "Flag_of_Argentina.svg";
  CURRENCY[2][1] = "Argentina";
  CURRENCY[2][2] = "Peso argentino";
  CURRENCY[3][0] = "Flag_of_Australia.svg";
  CURRENCY[3][1] = "Australia";
  CURRENCY[3][2] = "Dollaro australiano";
  CURRENCY[4][0] = "Flag_of_Barbados.svg";
  CURRENCY[4][1] = "Barbados";
  CURRENCY[4][2] = "Dollaro";
  CURRENCY[5][0] = "Flag_of_Bangladesh.svg";
  CURRENCY[5][1] = "Bangladesh";
  CURRENCY[5][2] = "Taka";
  CURRENCY[6][0] = "Flag_of_Bulgaria.svg";
  CURRENCY[6][1] = "Bulgaria";
  CURRENCY[6][2] = "Lev";
  CURRENCY[7][0] = "Flag_of_Bahrain.svg";
  CURRENCY[7][1] = "Bahrain";
  CURRENCY[7][2] = "Dinaro";
  CURRENCY[8][0] = "Flag_of_Bermuda.svg";
  CURRENCY[8][1] = "Bermuda";
  CURRENCY[8][2] = "Dollaro delle Bermuda";
  CURRENCY[9][0] = "Flag_of_Brazil.svg";
  CURRENCY[9][1] = "Brasile";
  CURRENCY[9][2] = "Real";
  CURRENCY[10][0] = "Flag_of_the_Bahamas.svg";
  CURRENCY[10][1] = "Bahamas";
  CURRENCY[10][2] = "Dollaro delle Bahamas";
  CURRENCY[11][0] = "Flag_of_Canada.svg";
  CURRENCY[11][1] = "Canada";
  CURRENCY[11][2] = "Dollaro canadese";
  CURRENCY[12][0] = "Flag_of_Switzerland.svg";
  CURRENCY[12][1] = "Svizzera";
  CURRENCY[12][2] = "Franco svizzero";
  CURRENCY[13][0] = "Flag_of_Chile.svg";
  CURRENCY[13][1] = "Cile";
  CURRENCY[13][2] = "Peso cileno";
  CURRENCY[14][0] = "Flag_of_the_People's_Republic_of_China.svg";
  CURRENCY[14][1] = "Cina";
  CURRENCY[14][2] = "Renminbi";
  CURRENCY[15][0] = "Flag_of_Colombia.svg";
  CURRENCY[15][1] = "Colombia";
  CURRENCY[15][2] = "Peso colombiano";
  CURRENCY[16][0] = "Flag_of_Costa_Rica.svg";
  CURRENCY[16][1] = "Costa Rica";
  CURRENCY[16][2] = "Colon";
  CURRENCY[17][0] = "Flag_of_the_Czech_Republic.svg";
  CURRENCY[17][1] = "Repubblica Ceca";
  CURRENCY[17][2] = "Corona ceca (Koruna)";
  CURRENCY[18][0] = "Flag_of_Denmark.svg";
  CURRENCY[18][1] = "Danimarca";
  CURRENCY[18][2] = "Corona danese (Krone)";
  CURRENCY[19][0] = "Flag_of_the_Dominican_Republic.svg";
  CURRENCY[19][1] = "Repubblica Dominicana";
  CURRENCY[19][2] = "Peso dominicano";
  CURRENCY[20][0] = "Flag_of_Algeria.svg";
  CURRENCY[20][1] = "Algeria";
  CURRENCY[20][2] = "Dinaro algerino";
  CURRENCY[21][0] = "Flag of Estonia.svg";
  CURRENCY[21][1] = "Estonia";
  CURRENCY[21][2] = "Corona estone (Kroon)";
  CURRENCY[22][0] = "Flag of Egypt.svg";
  CURRENCY[22][1] = "Egitto";
  CURRENCY[22][2] = "Lira egiziana";
  CURRENCY[23][0] = "Flag of Europe.svg";
  CURRENCY[23][1] = "Europa";
  CURRENCY[23][2] = "Euro";
  CURRENCY[24][0] = "Flag of Fiji.svg";
  CURRENCY[24][1] = "Figi";
  CURRENCY[24][2] = "Dollaro delle Figi";
  CURRENCY[25][0] = "Flag of the United Kingdom.svg";
  CURRENCY[25][1] = "Regno Unito";
  CURRENCY[25][2] = "Sterlina inglese";
  CURRENCY[26][0] = "Flag of Hong Kong.svg";
  CURRENCY[26][1] = "Hong Kong";
  CURRENCY[26][2] = "Dollaro di Hong Kong";
  CURRENCY[27][0] = "Flag of Croatia.svg";
  CURRENCY[27][1] = "Croazia";
  CURRENCY[27][2] = "Kuna";
  CURRENCY[28][0] = "Flag of Hungary.svg";
  CURRENCY[28][1] = "Ungheria";
  CURRENCY[28][2] = "Fiorino ungherese (Forint)";
  CURRENCY[29][0] = "Flag of Indonesia.svg";
  CURRENCY[29][1] = "Indonesia";
  CURRENCY[29][2] = "Rupia indonesiana";
  CURRENCY[30][0] = "Flag of Israel.svg";
  CURRENCY[30][1] = "Israele";
  CURRENCY[30][2] = "Shekel israeliano";
  CURRENCY[31][0] = "Flag of India.svg";
  CURRENCY[31][1] = "India";
  CURRENCY[31][2] = "Rupia";
  CURRENCY[32][0] = "Flag of Iraq.svg";
  CURRENCY[32][1] = "Iraq";
  CURRENCY[32][2] = "Dinaro iracheno";
  CURRENCY[33][0] = "Flag of Iran.svg";
  CURRENCY[33][1] = "Iran";
  CURRENCY[33][2] = "Riyal iraniano";
  CURRENCY[34][0] = "Flag of Iceland.svg";
  CURRENCY[34][1] = "Islanda";
  CURRENCY[34][2] = "Corona islandese (Króna)";
  CURRENCY[35][0] = "Flag of Jamaica.svg";
  CURRENCY[35][1] = "Giamaica";
  CURRENCY[35][2] = "Dollaro giamaicano";
  CURRENCY[36][0] = "Flag of Jordan.svg";
  CURRENCY[36][1] = "Giordania";
  CURRENCY[36][2] = "Dinaro giordano";
  CURRENCY[37][0] = "Flag of Japan.svg";
  CURRENCY[37][1] = "Giappone";
  CURRENCY[37][2] = "Yen";
  CURRENCY[38][0] = "Flag of Kenya.svg";
  CURRENCY[38][1] = "Kenya";
  CURRENCY[38][2] = "Scellino keniota";
  CURRENCY[39][0] = "Flag_of_South_Korea.svg";
  CURRENCY[39][1] = "Corea del Sud";
  CURRENCY[39][2] = "Won Sudcoreano";
  CURRENCY[40][0] = "Flag of Kuwait.svg";
  CURRENCY[40][1] = "Kuwait";
  CURRENCY[40][2] = "Dinaro kuwaitiano";
  CURRENCY[41][0] = "Flag of Lebanon.svg";
  CURRENCY[41][1] = "Libano";
  CURRENCY[41][2] = "Lira libanese";
  CURRENCY[42][0] = "Flag of Sri Lanka.svg";
  CURRENCY[42][1] = "Sri Lanka";
  CURRENCY[42][2] = "Rupia singalese";
  CURRENCY[43][0] = "Flag of Madagascar.svg";
  CURRENCY[43][1] = "Madagascar";
  CURRENCY[43][2] = "Ariary malgascio";
  CURRENCY[44][0] = "Flag of Mauritius.svg";
  CURRENCY[44][1] = "Mauritius";
  CURRENCY[44][2] = "Rupia mauriziana";
  CURRENCY[45][0] = "Flag of Mexico.svg";
  CURRENCY[45][1] = "Messico";
  CURRENCY[45][2] = "Peso messicano";
  CURRENCY[46][0] = "Flag of Malaysia.svg";
  CURRENCY[46][1] = "Malaysia";
  CURRENCY[46][2] = "Ringgit";
  CURRENCY[47][0] = "Flag of Norway.svg";
  CURRENCY[47][1] = "Norvegia";
  CURRENCY[47][2] = "Corona norvegese (Krone)";
  CURRENCY[48][0] = "Flag of New Zealand.svg";
  CURRENCY[48][1] = "Nuova Zelanda";
  CURRENCY[48][2] = "Dollaro neozelandese";
  CURRENCY[49][0] = "Flag of Oman.svg";
  CURRENCY[49][1] = "Oman";
  CURRENCY[49][2] = "Riyal dell'Oman";
  CURRENCY[50][0] = "Flag_of_Peru.svg";
  CURRENCY[50][1] = "Perù";
  CURRENCY[50][2] = "Nuevo Sol";
  CURRENCY[51][0] = "Flag_of_the_Philippines.svg";
  CURRENCY[51][1] = "Filippine";
  CURRENCY[51][2] = "Peso Filippino";
  CURRENCY[52][0] = "Flag_of_Pakistan.svg";
  CURRENCY[52][1] = "Pakistan";
  CURRENCY[52][2] = "Rupia pakistana";
  CURRENCY[53][0] = "Flag_of_Poland.svg";
  CURRENCY[53][1] = "Polonia";
  CURRENCY[53][2] = "Zloty (złoty)";
  CURRENCY[54][0] = "Flag_of_Qatar.svg";
  CURRENCY[54][1] = "Qatar";
  CURRENCY[54][2] = "Riyal";
  CURRENCY[55][0] = "Flag_of_Romania.svg";
  CURRENCY[55][1] = "Romania";
  CURRENCY[55][2] = "Leu";
  CURRENCY[56][0] = "Flag_of_Russia.svg";
  CURRENCY[56][1] = "Russia";
  CURRENCY[56][2] = "Rublo russo";
  CURRENCY[57][0] = "Flag_of_Saudi_Arabia.svg";
  CURRENCY[57][1] = "Arabia Saudita";
  CURRENCY[57][2] = "Riyal";
  CURRENCY[58][0] = "Flag_of_Sweden.svg";
  CURRENCY[58][1] = "Svezia";
  CURRENCY[58][2] = "Corona svedese (Krona)";
  CURRENCY[59][0] = "Flag_of_Singapore.svg";
  CURRENCY[59][1] = "Singapore";
  CURRENCY[59][2] = "Dollaro";
  CURRENCY[60][0] = "Flag_of_Slovakia.svg";
  CURRENCY[60][1] = "Slovacchia";
  CURRENCY[60][2] = "Corona slovacca (Koruna)";
  CURRENCY[61][0] = "Flag_of_Thailand.svg";
  CURRENCY[61][1] = "Thailandia";
  CURRENCY[61][2] = "Baht";
  CURRENCY[62][0] = "Flag_of_Tunisia.svg";
  CURRENCY[62][1] = "Tunisia";
  CURRENCY[62][2] = "Dinaro tunisino";
  CURRENCY[63][0] = "Flag_of_Turkey.svg";
  CURRENCY[63][1] = "Turchia";
  CURRENCY[63][2] = "Nuova lira turca";
  CURRENCY[64][0] = "Flag_of_Trinidad_and_Tobago.svg";
  CURRENCY[64][1] = "Trinidad e Tobago";
  CURRENCY[64][2] = "Dollaro";
  CURRENCY[65][0] = "Flag_of_the_Republic_of_China.svg";
  CURRENCY[65][1] = "Taiwan";
  CURRENCY[65][2] = "Dollaro taiwanese";
  CURRENCY[66][0] = "Flag_of_the_United_States.svg";
  CURRENCY[66][1] = "Stati Uniti d'America";
  CURRENCY[66][2] = "Dollaro statunitense";
  CURRENCY[67][0] = "Flag_of_Venezuela.svg";
  CURRENCY[67][1] = "Venezuela";
  CURRENCY[67][2] = "Bolivar fuerte";
  CURRENCY[68][0] = "Flag_of_Vietnam.svg";
  CURRENCY[68][1] = "Vietnam";
  CURRENCY[68][2] = "Dong";
  CURRENCY[69][0] = "Bubi_tribal_flag.svg";
  CURRENCY[69][1] = "Guinea Equatoriale";
  CURRENCY[69][2] = "Franco CFA";
  CURRENCY[70][0] = "3by2white.svg";
  CURRENCY[70][1] = "Caraibi Orientali";
  CURRENCY[70][2] = "Dollaro dei Caraibi Orientali";
  CURRENCY[71][0] = "Flag_of_EAC.svg";
  CURRENCY[71][1] = "Stati dell'Africa Orientale";
  CURRENCY[71][2] = "Franco CFA";
  CURRENCY[72][0] = "Flag of French Polynesia.svg";
  CURRENCY[72][1] = "Polinesia Francese e Nuova Caledonia";
  CURRENCY[72][2] = "Franco CFP";
  CURRENCY[73][0] = "Flag of South Africa.svg";
  CURRENCY[73][1] = "Sudafrica";
  CURRENCY[73][2] = "Rand";
  CURRENCY[74][0] = "Flag_of_Zambia.svg";
  CURRENCY[74][1] = "Zambia";
  CURRENCY[74][2] = "Kwacha zambiano";

  std::string MINERALS[4][2];
  MINERALS[0][0] = "XAG" ;
  MINERALS[0][1] = "Argento" ;
  MINERALS[1][0] = "XAU" ;
  MINERALS[1][1] = "Oro" ;
  MINERALS[2][0] = "XPD";
  MINERALS[2][1] = "Palladio";
  MINERALS[3][0] = "XPT";
  MINERALS[3][1] = "Platino";

  bool alpha;
  int c = 0;
  int d = 0;
  std::string text;
  std::stringstream sstr;
  wikipp::extended::currency get;
  sstr << "{|class='wikitable sortable plainlinks' border='1' cellpadding='3' cellspacing='0' style='text-align:center; margin-top:.5em; margin-bottom:.5em; border:1px solid #bbb; border-collapse:collapse;'" << std::endl;
  sstr << "|-bgcolor=#dddddd" << std::endl;
  sstr << "!width=5%|" << std::endl;
  sstr << "!width=20%|Stato" << std::endl;
  sstr << "!width=20%|Moneta" << std::endl;
  sstr << "!width=5%|Sigla" << std::endl;
  sstr << "!width=15%|Da <small>(con questa quantità si può acquistare 1 " + CURTBP[intBc] + ")</small>" << std::endl;
  sstr << "!width=15%|A <small>(con un " + CURTBP[intBc] + " si può acquistare questa quantità)</small>" << std::endl;
  while(c < 75)
  {
    if (bc != CUR[c])
    {
      sstr << "|-" << std::endl;
      sstr << "|[[Immagine:" + CURRENCY[c][0] + "|20px]]" << std::endl;
      if (c < 70 || c > 72)
        sstr << "|[[" + CURRENCY[c][1] + "]]" << std::endl;
      else
        sstr << "|" + CURRENCY[c][1] << std::endl;
      while (d < 7 && alpha == 0)
      {
        if (CUR[c] == CURTBP[d])
        {
          sstr << "|[[" + page + "/" + CUR[c] + "|" + CURRENCY[c][2] + "]]"<< std::endl;
          alpha = 1;
        }
        d++;
      }
      d = 0;
      if (alpha == 0)
        sstr << "|" + CURRENCY[c][2] << std::endl;
      else
        alpha = 0;
      while (d < 7 && alpha == 0)
      {
        if (CUR[c] == CURTBP[d])
        {
          sstr << "|[[" + page + "/" + CUR[c] + "|" + CUR[c] + "]]"<< std::endl;
          alpha = 1;
        }
        d++;
      }
      d = 0;
      if (alpha == 0)
        sstr << "|" + CUR[c] << std::endl;
      else
        alpha = 0;
      sstr << get.yahooBotB(bc,CUR[c]) << std::endl;
    }
    c++;
  }
  sstr << "|}" << std::endl;

  c = 0;

  sstr << "{|class='wikitable sortable plainlinks' border='1' cellpadding='3' cellspacing='0' style='text-align:center; margin-top:.5em; margin-bottom:.5em; border:1px solid #bbb; border-collapse:collapse;'" << std::endl;
  sstr << "|-bgcolor=#dddddd" << std::endl;
  sstr << "!width=45%|Minerali (un oncia, o 31 grammi)" << std::endl;
  sstr << "!width=5%|Sigla" << std::endl;
  sstr << "!width=15%|Da <small>(con questa quantità si può acquistare 1 " + CURTBP[intBc] + ")</small>" << std::endl;
  sstr << "!width=15%|A <small>(con un " + CURTBP[intBc] + " si può acquistare questa quantità)</small>" << std::endl;
  while(c < 5)
  {
    if (bc != MINERALS[c][0])
    {
      sstr << "|-" << std::endl;
      sstr << "|" + MINERALS[c][1] << std::endl;
      sstr << "|" + MINERALS[c][0] << std::endl;
      sstr << get.yahooBotB(bc,MINERALS[c][0]) << std::endl;
    }
    c++;
  }
  sstr << "|}" << std::endl;

  std::vector<int> time = wikipp::libs::dati::dateTime();
  sstr << "Aggiornato alle " << time[2] << ":" << time[1] << ":" << time[0];
  sstr << " del " << time[3] << "/" << time[4] << "/" << time[5] << "." << std::endl << std::endl;
  sstr << "I dati potrebbero essere ritardati di 15 o 20 minuti.";
  text = sstr.str();
  wikipp::wiki::write::writePage(url,page + "/" + bc,text,"CurrencyBot: Aggiorno i cambi delle monete");
  get.savefile(bc);
}

int main( int argc, char **argv )
  {
    std::string user( wikipp::libs::prgdata::getUsername() );
    std::string pass( wikipp::libs::prgdata::getPassword() );
    std::string proj( wikipp::libs::prgdata::getProject() );
    std::string page( wikipp::libs::prgdata::getPage() );
    std::string tizo( wikipp::libs::prgdata::getTimeZone() );

    if ( argv[1] == "a" )
    {
      wikipp::wiki::login::wikiLogin(proj, user, pass);
      a(proj, page, tizo);
    }
    else
      if ( argv[1] = "b" )
      {
        int c = 0;
        std::string CURTBP[7];
        CURTBP[0] = "USD";
        CURTBP[1] = "EUR";
        CURTBP[2] = "JPY";
        CURTBP[3] = "CAD";
        CURTBP[4] = "GBP";
        CURTBP[5] = "AUD";
        CURTBP[6] = "CHF";

        wikipp::wiki::login::wikiLogin(proj, user, pass);

        while (c < 7)
        {
          b(proj, c, CURTBP[c], page, tizo);
          c++;
        }
      }
      else
      {
        wikipp::wiki::login::wikiLogin(proj, user, pass);
        a(proj, page, tizo);

        int c = 0;
        std::string CURTBP[7];
        CURTBP[0] = "USD";
        CURTBP[1] = "EUR";
        CURTBP[2] = "JPY";
        CURTBP[3] = "CAD";
        CURTBP[4] = "GBP";
        CURTBP[5] = "AUD";
        CURTBP[6] = "CHF";

        wikipp::wiki::login::wikiLogin(proj, user, pass);

        while (c < 7)
        {
          b(proj, c, CURTBP[c], page, tizo);
          c++;
        }
      }

    return 0;
  }

#endif
