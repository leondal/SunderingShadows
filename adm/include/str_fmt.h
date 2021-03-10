/* simple string formatter to indent lines after first 
   Valodin ---rehack 10/2/92 */

#if !defined(VAL_STR_FMT)
#define VAL_STR_FMT

string str_fmt(string str, int spaces)
{
   string line, first, last, outputstr, spacer;
   int i;
   int tempspaces;

   if (!str)
      return 0;
   outputstr = "";

   spacer = "";
   for (i = 0; i < spaces; i++)
      spacer += " ";
   tempspaces = 0;

   while(strlen(str) > 0)
   { 
      if (outputstr != "") 
         outputstr += spacer; 
      line = "";
      first  = "";
      while((strlen(str + first) > 0) && (!(strlen(line)) || 
            (strlen(line + first) < (78 - tempspaces))))
      { 
         line += first;
         if (sscanf(str, "%s %s", first, last) != 2)
         { 
            first = str;
            str = ""; 
         }
         else
         { 
            first += " ";
            str = last; 
         }
      }
      str = first + str;
      outputstr += line + "\n";
      tempspaces = spaces;
   }
   return outputstr; 
}
#endif
