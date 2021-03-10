/*
// File: substr.c
// This is a simul_efun module.
// Original author: Sulam@TMI
// This file is a part of the TMI distribution mudlib.
// Please retain this header if you use it.
// This function recursively replaces a key with a string.
// Variables:
// str      The text that needs formatting
// match    The key that is getting replaced
// replace  What to replace match with
// Returns:
// The string we end up with.
// Note: this is very similar to replace_string().  As they are
// both slightly different, they are both here until a suitable
// solution can be found.
*/

/**
 * This function recursively replaces a key with a string.
 *
 * @param str Text to format
 * @param match Substring to replace
 * @param replace String to replace with
 * @return String
 */
string
substr(string str, string match, string replace)
{
   string foo, fii;
   string reg;
   /*
   // Do some checking first.
   */
   if( !str || !match ) return "";
   if( !stringp(str) || !stringp(match) || !stringp(replace) )
      return "";
   if( !replace ) replace = "";
   /*
   // The loop to replace the text
   */
   reg = "";
   while( sscanf(str, "%s"+match+"%s", foo, fii) )
   {
      if( !foo ) foo = "";
      if( !fii ) fii = "";
      reg +=foo + replace;
      str =str[strlen(foo)+strlen(match)..strlen(str)];
   }
   reg += fii;
   return reg;
}
