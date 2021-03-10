//  Created by Ignatius, for ShadowGate
//  Coded 10 February, 1995
//  Definitions for Antioch area

#define MON             "/d/antioch/mon/"
#define OBJT            "/d/antioch/obj/"
#define ARM             "/d/antioch/armour/"
#define WEAP            "/d/antioch/weapon/"
#define ANTIOCH         "/d/antioch/"
#define VIL             "/d/antioch/village/"
#define MANS            "/d/antioch/village/mansion/"
#define GAR             "/d/antioch/garrison/"
#define WILD            "/d/antioch/wild/mount/"
#define ISL	    "/d/antioch/island/"
#define FOREST          "/d/antioch/wild/forest/"

#define PIT             "/d/antioch/village/pit/"
 
#define tp              this_player()
#define tn              this_player()->query_name()
#define Tn              this_player()->query_cap_name()
#define NAME            query_cap_name()
#define nAME            query_name()
#define POSS            query_possessive()
#define OBJ             query_objective()
#define SUBJ            query_subjective()
#define TPENV           environment(this_player())
#define HIS             this_player()->query_possessive()
#define HIM             this_player()->query_objective()
#define HIMSELF         reflexive(this_player())
#define HE              this_player()->query_subjective()
#define ENV             environment
#define FP              find_player
 
#define To              this_object()
