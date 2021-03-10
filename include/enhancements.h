/**
 * Definitions for weapon and armor enhancements for magus, paladin and whatever might come later.
 * Venger
 */

#define VALID_WEAPON_ENHANCEMENTS ([ \
                                "flaming" : ([ "property" : "fire en_dam", "cost" : 1 ]), \
                                "frost" : ([ "property" : "cold en_dam", "cost" : 1 ]), \
                                "shock" : ([ "property" : "electricity en_dam", "cost" : 1 ]), \
                                "thundering" : ([ "property" : "sonic en_dam", "cost" : 1 ]), \
                                "corrosive" : ([ "property" : "acid en_dam", "cost" : 1 ]), \
                                "flaming burst" : ([ "property" : "fire en_dam burst", "cost" : 2 ]), \
                                "icy burst" : ([ "property" : "cold en_dam burst", "cost" : 2 ]), \
                                "shocking burst" : ([ "property" : "electricity en_dam burst", "cost" : 2 ]), \
                                "thundering burst" : ([ "property" : "sonic en_dam burst", "cost" : 2 ]), \
                                "corrosive burst" : ([ "property" : "acid en_dam burst", "cost" : 2 ]), \
                                "holy" : ([ "property" : "alignment 147", "cost" : 1 ]), \
                                "unholy" : ([ "property" : "alignment 369", "cost" : 1 ]), \
                                "axiomatic" : ([ "property" : "alignment 123", "cost" : 1 ]), \
                                "anarchic" : ([ "property" : "alignment 789", "cost" : 1 ]), \
                                "keen" : ([ "property" : "keen weapon", "cost" : 1 ]), \
                                "speed" : ([ "property" : "speedy weapon", "cost" : 3 ]), \
                            ]);

#define MAGUS_WEAPON_ENHANCEMENTS ({ "flaming", "frost", "shock", "flaming burst", "icy burst", "shocking burst", });
#define THUNDERING_ENHANCEMENTS ({ "thundering", "thundering burst", });
#define CORROSIVE_ENHANCEMENTS ({ "corrosive", "corrosive burst", });
#define ALIGNMENT_ENHANCEMENTS ({ "holy", "unholy", "axiomatic", "anarchic", });
//magus pending: dancing, vorpal, speedy, keen.

#define PALADIN_WEAPON_ENHANCEMENTS ({ "flaming", "flaming burst", "holy", "unholy", "axiomatic", "anarchic", });
//paladin pending: brilliant energy, defending, disruption, merciful, speedy, keen.
//antipaladin pending: vicious, wounding, vorpal, keen.

#define CLERIC_WEAPON_ENHANCEMENTS ({ "holy", "unholy", "axiomatic", "anarchic", });

#define VALID_ARMOR_ENHANCEMENTS ([ \
                                "light fortification" : ([ "property" : "fortification 25", "cost" : 1 ]), \
                                "moderate fortification" : ([ "property" : "fortification 50", "cost" : 3 ]), \
                                "heavy fortification" : ([ "property" : "fortification 75", "cost" : 5 ]), \
                                "acid energy resistance" : ([ "property" : "acid en_res", "cost" : 4 ]), \
                                "cold energy resistance" : ([ "property" : "cold en_res", "cost" : 4 ]), \
                                "electricity energy resistance" : ([ "property" : "electricity en_res", "cost" : 4 ]), \
                                "fire energy resistance" : ([ "property" : "fire en_res", "cost" : 4 ]), \
                                "sonic energy resistance" : ([ "property" : "sonic en_res", "cost" : 4 ]), \
                                "improved acid energy resistance" : ([ "property" : "acid en_res improved", "cost" : 6 ]), \
                                "improved cold energy resistance" : ([ "property" : "cold en_res improved", "cost" : 6 ]), \
                                "improved electricity energy resistance" : ([ "property" : "electricity en_res improved", "cost" : 6 ]), \
                                "improved fire energy resistance" : ([ "property" : "fire en_res improved", "cost" : 6 ]), \
                                "improved sonic energy resistance" : ([ "property" : "sonic en_res improved", "cost" : 6 ]), \
                            ]);

#define MAGUS_ARMOR_ENHANCEMENTS ({ "light fortification", "moderate fortification", "heavy fortification", \
                                    "acid energy resistance", "cold energy resistance", "electricity energy resistance", "fire energy resistance", "sonic energy resistance", });

#define PALADIN_ARMOR_ENHANCEMENTS ({ "light fortification", "moderate fortification", "heavy fortification", \
                                    "acid energy resistance", "cold energy resistance", "electricity energy resistance", "fire energy resistance", "sonic energy resistance", \
                                    "improved acid energy resistance", "improved cold energy resistance", "improved electricity energy resistance", "improved fire energy resistance", "improved sonic energy resistance", });