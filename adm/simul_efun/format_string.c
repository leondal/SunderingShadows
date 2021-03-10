/*
// File: format_string.c
// A simul_efun from the wonderful folks at Portals.
// This is now a part of the TMI distribution mudlib.
// Delete header files at own risk.
// Purpose: convert a format such as one used by printf or sprintf 
// into a string with the accompanying variables.
// Vaguely, vaguely resembles sprintf().
// Useful if you did not compile with PRINT_F defined.
*/

string format_string (string format, mixed *variables)
{
   string *tmp, ret;
   int i, max;
   
   tmp = explode (format,"%s");
   if (!tmp || sizeof(tmp) < 2 || !variables)
      return format;
   if (sizeof(tmp) < sizeof(variables)) max = sizeof(variables);
   else max = sizeof(tmp);
   ret = "";
   for (i = 0 ; i < max; i ++) {
      ret += tmp[i] + variables[i];
   }
   return ret;
}
