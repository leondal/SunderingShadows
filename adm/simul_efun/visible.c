/*
// File:	visible.c
// Mudlib:	TMI-II
// Author:	Pallando
// Real Name:	Douglas Reay
// Syntax:      varargs int visible( object detectee, object detector )
// Returns:     1 if detector may be allowed to know that the detectee exists
//		0 if detector may not penetrate detectee's invisibility.
// Purpose:	Should be called by any command that might let one user know
//              whether another user is logged on.
// Date V1.0:   1992 December 22
//      V1.1:   Ideas about generality from Mobydick.
//      V2.0:   Changed to Nightmare syntax, Pallando (93-05-28)
*/

varargs int visible( object detectee_obj, object detector_obj )
{
  string detector_euid;
  int detector_rank;
  int detectee_vis;

  if( !detectee_obj ) return 0;
  if( !detector_obj ) detector_euid = "TEMP";
  else detector_euid = geteuid( detector_obj );

// Find the detector's rank
  if( detector_obj ) detector_rank = wizardp( detector_obj );
  if( member_group( detector_euid, "assist" ) ) detector_rank = 2;

// Find the detectee's visibility
  detectee_vis = ( detectee_obj-> query_invis() ? 1 : 0 );
  if( hiddenp( detectee_obj ) ) detectee_vis = 2;

// Compare them
  if( detectee_vis > detector_rank ) return 0; // detector can't see detectee.
  return 1; // detector can see detectee.
}
