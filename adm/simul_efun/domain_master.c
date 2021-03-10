/*
// File:       /adm/simul_efun/domain_master.c
// Purpose::
// Syntax:     string domain_master( mixed domain ) 
// Arguments:  domain is an object (or a string naming the object's domain)
// Returns:    the domain's master object, or 0 if one doesn't exist.
// History::
// Author:     Douglas Reay (Pallando @ TMI, Nightmare, etc)
// Date V1.0:  93-06-05
// Mudlib:     Nightmare
// Comments:   /d/X/adm/d_master.c is used on TMI mudlibs for file permissions
//             It is used on Nightmare for domain dependant object properties
//             This efun is to help muds who take from both mudlibs.
*/

string domain_master( mixed domain )
{
  if( objectp( domain ) ) sscanf( file_name( domain ), "/d/%s/%*s", domain );
  if( !stringp( domain ) ) return 0;
  domain = "/d/" + domain + "/adm/master";
  if( file_size( domain + ".c" ) < 0 ) return 0;
  return domain;
}
