// office : ({ title, jurisdiction, minpower, nobid })

#define VALID_OFFICES ([ \
"shadow councillor 1" : ({ "Councillor of the City of Shadow", "shadow", 100, 0 }), \
"shadow councillor 2" : ({ "Councillor of the City of Shadow", "shadow", 100, 0 }), \
"shadow councillor 3" : ({ "Councillor of the City of Shadow", "shadow", 100, 0 }), \
"shadow guard captain" : ({ "Captain of the Shadow Guard", "shadow", 200, 1 }), \
"shadow mayor" : ({ "Lord Mayor of Shadow", "shadow", 200, 0 }), \
"shadow thieves guildmaster" : ({ "Master of the Thieves' Guild of Shadow", "shadow thieves", 100, 0 }), \
"shadow thieves warden 1" : ({ "Warden of the Shadow Thieves' Guild", "shadow thieves", 0, 1 }), \
"shadow thieves warden 2" : ({ "Warden of the Shadow Thieves' Guild", "shadow thieves", 0, 1 }), \
])

// Position Element Array Definitions.  Corresponds to array elements of 
// VALID_OFFICES above.
// DO NOT MESS WITH THESE UNLESS YOU KNOW WHAT YOU ARE DOING!
// If you are wondering whether you know what you are doing, then you
// probably don't.  See above.
#define TITLE 0
#define JURISDICTION 1
#define MINPOWER 2
#define NOBID 3

// Legal Jurisdictions - No big deal, just make sure that if you 
// create a new office, that there is a jurisdiction for it below.
// DO NOT remove jurisdictions that are for currently active offices!
#define VALID_JURISDICTIONS ({ \
"asgard", \
"seneca", \
"shadow", \
"shadow thieves", \
"tharis", \
"daggerdale", \
"tonovi", \
"torm", \
"antioch", \
"verbobone", \
})
