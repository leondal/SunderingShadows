//ki caps at 6 per spell - Saide - KI_COST_PER_LEVEL used by the "ki" command to let players know
//how much a particular spell costs to use
#define KI_COST_PER_LEVEL ([ 3 : 2, 5 : 3, 7 : 4, 9 : 5, 11 : 6, 13 : 6, 15 : 6, 17 : 6])

//because of the way that it is set up - each spell needs to be in KI_COST with a KI COST associated with it
//furthermore, they must also be listed as an array in KI_SPELLS - the number is the literal level that the
//monk must be in order to get access to those spells

#define KI_COST ([\
                    "way of the shadow" : ([\
                        "darkness" : 2, "darkvision" : 2, "ghost step" : 2, "cloak of shadows" : 6,\
                        "shadow stride" : 4, "shadow sight" : 5, "shadow travel" : 5]), \
                    "way of the elements" : ([\
                        "burning hands" : 2, "fly" : 2,\
                        "thunder wave" : 3, "hold person" : 3, "fireball" : 4, "shatter" : 4,\
                        "wall of stone" : 5, "gaseous form" : 5, "stoneskin" : 6, "gale fist" : 6,\
                        "wall of fire" : 6, "gust of wind" : 6, "cone of cold" : 6, "fire storm" : 6,\
                        "monsoon" : 6]),\
                    "grandmaster of the way" : ([\
                        "darkness" : 2, "darkvision" : 2, "ghost step" : 2, "cloak of shadows" : 6,\
                        "shadow stride" : 4, "shadow sight" : 5, "burning hands" : 2, "fly" : 2,\
                        "thunder wave" : 3, "hold person" : 3, "fireball" : 4, "shatter" : 4,\
                        "wall of stone" : 5, "gaseous form" : 5, "stoneskin" : 6, "gale fist" : 6,\
                        "wall of fire" : 6, "gust of wind" : 6, "cone of cold" : 6, "fire storm" : 6,\
                        "monsoon" : 6, "shadow travel" : 5 ]), ])

#define KI_SPELLS (["way of the shadow" : ([\
                    3  : ({ "darkvision", "darkness", "ghost step" }),\
                    7  : ({ "shadow stride" }),\
                    9  : ({ "shadow sight" }),\
                    11 : ({ "cloak of shadows", "shadow travel" }),]),  \
                    "way of the elements" : ([\
                    3  : ({ "burning hands", "fly" }),\
                    5  : ({ "thunder wave", "hold person" }),\
                    7  : ({ "fireball", "shatter" }),\
                    9  : ({ "wall of stone", "gaseous form" }),\
                    11 : ({ "stoneskin", "gale fist" }),\
                    13 : ({ "wall of fire", "gust of wind" }),\
                    15 : ({ "cone of cold" }),\
                    17 : ({ "fire storm", "monsoon" }),]),\
                    "grandmaster of the way" : ([\
                    3 :  ({ "darkvision", "darkness", "ghost step", "burning hands", "fly" }),\
                    5 :  ({ "thunder wave", "hold person" }),\
                    7 :  ({ "shadow stride", "fireball", "shatter" }),\
                    9 :  ({ "shadow sight", "wall of stone", "gaseous form" }),\
                    11 : ({ "cloak of shadows", "stoneskin", "gale fist", "shadow travel" }), \
                    13 : ({ "wall of fire", "gust of wind" }),\
                    15 : ({ "cone of cold" }),\
                    17 : ({ "fire storm", "monsoon" }),]),])
