// Pator@ShadowGate
// April 17 1996
// All the defines that druids need


// The levels within the realms of ShadowGate
#define   GOD       2000    
#define   ARCH      1750
#define   ELDER     1500
#define   OVERSEER  1350
#define   DEVELOPER 1250
#define   CREATOR   1000
#define   APPRENTICE 500
#define   BUILDER    250
#define   HIGHMORTAL  20
#define   MORTAL       0

// All the names with the druidclass that have special privilidges
#define RESTRICTED_NAMES ({ "DRUIDMASTER", "ARCANEDRUID" })

// All the players that are Council_Members
// <Name> : <LEVEL>
#define DRUID_LEVELS ([ \
     "pator" : "DRUIDMASTER", \
     "svaha" : "ARCANEDRUID", \
                      ])

#define RANKING ([ \
	"DRUIDMASTER" : 6, \
	"ARCANEDRUID" : 5, \
	"CIRCLEDRUID" : 4, \
	"HERBALDRUID" : 3, \
	"HIEROPHANT"  : 2, \
	"DRUID"	      : 1, \
	"NO_DRUID"    : 0, \
	        ])

#define RANK_STRING ([ \
	6 : "DRUIDMASTER", \
	5 : "ARCANEDRUID", \
	4 : "CIRCLEDRUID", \
	3 : "HERBALDRUID", \
	2 : "HIEROPHANT" , \
	1 : "DRUID"	 , \
	0 : "NO_DRUID"   , \
	        ])

// The nice print of the classlevels
#define NAMEFORMAT ([ \
     "DRUIDMASTER"  : "DruidMaster",    \
     "ARCANEDRUID"  : "ArcaneDruid",    \
     "CIRCLEDRUID"  : "CircleDruid",    \
     "HERBALDRUID"  : "HerbalDruid",    \
     "HIEROPHANT"   : "Hierophant",     \
     "DRUID"        : "Druid",          \
     "NO_DRUID"     : "No Druid",       \
           ])

// The levels a druid must have to reach a specific classlevel
#define LEVELS ([ \
     6    : ELDER,      \
     5    : CREATOR,    \
     4    : CREATOR,    \
     3    : APPRENTICE, \
     2    : HIGHMORTAL, \
     0    : MORTAL,     \
                ])

// The strings belonging to the LEVELS
#define LEVEL_STRING ([  \
     6    : "Elder",     \
     5    : "Creator",   \
     4    : "Creator",   \
     3    : "Apprentice",\
     2    : "HighMortal",\
     1    : "Mortal",    \
     0    : "Mortal",    \
                      ])

// The material for the amulets
#define AMULET_MATERIAL  ([ \
     6    : "electrum",  \
     5    : "platinum",  \
     4    : "gold",      \
     3    : "silver",    \
     2    : "brass",     \
     1    : "cast iron", \
     0    : "paper",     \
                          ])

#define DRUID_DIR       "/d/priest/"
#define DRUID_LOG       DRUID_DIR+"mistletoe/log/"
#define DRUID_LOG_NEW   DRUID_LOG+"new"
#define DRUID_LOG_DATA  DRUID_LOG+"data"
#define PRIEST_SPELL_DIR	"/cmds/priest/_"

#define MISTLETOE_SAVE          DRUID_DIR+"mistletoe/MS_"
#define ABILITIES_DIR           DRUID_DIR+"abilities/"
#define DRUID_OBJECT_DIR        DRUID_DIR+"obj/"
#define DRUID_DOC_DIR		DRUID_DIR+"docs/"
