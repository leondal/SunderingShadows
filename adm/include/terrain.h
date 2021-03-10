//Travel means
// Pator@ShadowGate-28/7/03: When adding new means, please add TRAVEL_PENALTY as well
#define PAVED_ROAD "paved road"
#define DIRT_ROAD  "dirt road"
#define BACK_ALLEY "back alley"
#define RUTTED_TRACK "rutted track"
#define FOOT_PATH "foot path"
#define GAME_TRACK "game track"
#define FRESH_BLAZE "fresh blaze"
#define SLICK_FLOOR "slick floor"
#define DECAYED_FLOOR "decayed floor"
#define STAIRWAY "stairway"
#define RUBBLE "rubble"
#define LEDGE "ledge"

#define TRAVEL ({PAVED_ROAD,DIRT_ROAD,BACK_ALLEY,RUTTED_TRACK,FOOT_PATH,GAME_TRACK,FRESH_BLAZE, SLICK_FLOOR, DECAYED_FLOOR, STAIRWAY, RUBBLE, LEDGE})

//Pator@ShadowGate
//28 July 2003
//Added TRAVEL_PENALTY which represents the % of change then a player will loose 1 stamina point when LEAVING the room with this travel property set

#define TRAVEL_PENALTY ([ \
	"paved road":10, \
	"dirt road":30, \
	"back alley":20, \
	"rutted track":30, \
	"foot path":20, \
	"game track":40, \
	"fresh blaze":50, \
	"slick floor":10, \
	"decayed floor":20, \
	"stairway":40, \
	"rubble":80, \
	"ledge":50, ])

#define LOW_P 			"low"
#define MEDIUM_P	"medium"
#define HIGH_P			"high"
#define EXTREME_P	"extreme"

#define DEFAULT_PENALTY_MULTIPLIER "medium"
#define TRAVEL_PENALTY_MULTIPLIER ([ \
        LOW_P:1, \
        MEDIUM_P:2, \
        HIGH_P:3, \
        EXTREME_P:4, ])

#define DEFAULT_STAMINA_PENALTY 1
#define isTerrainPenalty(x) (member_array(x,keys(TRAVEL)) != -1)
#define isTerrainPenaltyMultiplier(x) (member_array(x,keys(TRAVEL_PENALTY_MULTIPLIER)) != -1)

#define HEAVY_FOREST "heavy forest"
#define LIGHT_FOREST "light forest"
#define JUNGLE "jungle"
#define DENSE_JUNGLE "dense jungle"
#define SCRUB_LANDS "scrub lands"
#define GRASSLANDS "grasslands"
#define SAVANNAH "savannah"
#define DESERT "desert"
#define DESERT_DUNES "desert dunes"
#define DESERT_ROCKS "desert rocks"
#define ROCKY "rocky"
#define HILLS "hills"
#define BRANCHES "branches"
#define OLD_MOUNTS "old mounts"
#define NEW_MOUNTS "new mounts"
#define SWAMP "swamp"
#define MARSH "marsh"
#define SNOW "snow"
#define ICE "ice"
#define SHALLOW_WATER "shallow water"
#define DEEP_WATER "deep water"
#define MEADOWLANDS "meadows"
#define BEACH "beach"
#define SHORE "shore"
#define BARREN "barren"
#define GLACIER "glacier"
#define RUINS "ruins"
#define BOATS "boats"

//civilization
#define CITY "city"
#define VILLAGE "village"
#define CEMETERY "cemetery"
#define GARDEN "garden"

#define CIVILIZATION ({CITY,VILLAGE,CEMETERY,GARDEN })
#define OUTSIDE ({\
 HEAVY_FOREST, \
 LIGHT_FOREST, \
 JUNGLE, \
 DENSE_JUNGLE, \
 SCRUB_LANDS, \
 GRASSLANDS, \
 HILLS, \
 SAVANNAH, \
 DESERT, \
 DESERT_DUNES, \
 DESERT_ROCKS, \
 ROCKY, \
 HILLS, \
 OLD_MOUNTS, \
 NEW_MOUNTS, \
 SWAMP, \
 MARSH, \
 SNOW, \
 ICE, \
 SHALLOW_WATER, \
 DEEP_WATER, \
 CITY, \
 VILLAGE, \
 CEMETERY, \
 GARDEN, \
 BEACH, \
 SHORE, \
 BARREN, \
 GLACIER, \
 MEADOWLANDS, \
 BRANCHES, \
 RUINS,\
 BOATS,\
})

//inside
#define STONE_BUILDING "stone building"
#define WOOD_BUILDING "wood building"
#define HUT "hut"
#define NAT_CAVE "nat cave"
#define BUILT_CAVE "built cave"
#define BUILT_TUNNEL "built tunnel"
#define NAT_TUNNEL "nat tunnel"

// adding RUINS & WATER to be able to be inside also 
// underwater in a water room is special of course, but water can be inside 
//  a cave for instance as well as outdoors  *Styx* 12/02

#define INSIDE ({ STONE_BUILDING, WOOD_BUILDING, HUT, NAT_CAVE , BUILT_CAVE, BUILT_TUNNEL, NAT_TUNNEL, BRANCHES, SHALLOW_WATER, DEEP_WATER, RUINS})+CIVILIZATION


#define TERRAIN INSIDE + OUTSIDE


#define isTerrain(x) (member_array(x,TERRAIN) != -1)
#define isInside(x) (member_array(x,INSIDE) != -1)
#define isOutside(x) (member_array(x,OUTSIDE) != -1)
#define isCivilization(x) (member_array(x,CIVILIZATION) != -1)
#define isTravel(x) (member_array(x,TRAVEL) != -1)

/* To group types for NWPs such as foraging, hunting, etc. per T's suggestion
   on the easiest way to get to the group from knowing terrain type.
   NOTE:  PLEASE do not add or remove any groups because some uses will
   rely on these being the only choices.
Also:  Be sure to add any new terrain types to the mapping.
 
*Styx*  7/2002
*/

#define NWP_LGAME 1
#define NWP_SMGAME 2
#define NWP_SPARSE 3
#define NWP_MARSH 4
#define NWP_DESERT 5
#define NWP_FROZEN 6
#define NWP_CAVES 7
#define NWP_FISH 8
#define NWP_STREET 9
#define NWP_BLDGS 10
#define NWP_BOATS 11

#define TERRAIN_GROUPS (["heavy forest":1, "light forest":1, \
"jungle":1, "dense jungle":1,\
"grasslands":2, "meadows": 2, "branches":2, "savannah":2, "garden":2,\
"hills":3, "scrub lands":3, "old mounts":3, "new mounts":3, "cemetery":3,\
"swamp":4, "marsh":4,\
"rocky":5, "desert":5, "desert dunes":5, "desert rocks":5, "barren":5, \
"snow":6, "ice":6, "glacier":6,\
"nat cave":7, "built cave":7, "built tunnel":7, "nat tunnel":7,\
"shallow water":8, "deep water":8, "beach":8, "shore":8,\
"city":9, "village":9,\
"stone building":10, "wood building":10, "hut":10,\
"boats": 11,])

