/**
 * @file
 */

#define COMMONFILE "/d/common/obj/"

mapping ARMORSMITH = ([]);
ARMORSMITH = ([
                  "banded mail":(["file":COMMONFILE"armour/banded","units":6]),
                  "barding":(["file":COMMONFILE"armour/pcbarding","units":2]),
                  "tower shield":(["file":COMMONFILE"armour/shield","units":3]),
                  "boots":(["file":COMMONFILE"clothing/shoes","units":2]),
                  "breastplate":(["file":COMMONFILE"armour/breastplate","units":4]),
                  "brigandine":(["file":COMMONFILE"armour/brigadine","units":4]),
                  "chain mail":(["file":COMMONFILE"armour/chain","units":5]),
                  "coif":(["file":COMMONFILE"armour/coif","units":2]),
                  "field plate":(["file":COMMONFILE"armour/field","units":8]),
                  "full plate":(["file":COMMONFILE"armour/fullplate","units":9]),
                  "gauntlets":(["file":COMMONFILE"armour/gauntlets","units":1]),
                  "greaves":(["file":COMMONFILE"armour/greaves","units":1]),
                  "helm":(["file":COMMONFILE"armour/helm","units":2]),
                  "plate mail":(["file":COMMONFILE"armour/plate","units":7]),
                  "ring mail":(["file":COMMONFILE"armour/ring","units":3]),
                  "scale mail":(["file":COMMONFILE"armour/scale","units":4]),
                  "shield":(["file":COMMONFILE"armour/mshield","units":2]),
                  "splint mail":(["file":COMMONFILE"armour/splint","units":7]),
                  ]);

mapping LEATHERWORK = ([]);
LEATHERWORK = ([
                   "barding":(["file":COMMONFILE"armour/pcleatherbarding","units":2,"type":"armor"]),
                   "belt":(["file":COMMONFILE"armour/belt","units":1]),
                   "backpack":(["file":COMMONFILE"misc/backpack","units":2]),
                   "breastplate":(["file":COMMONFILE"armour/leather_plate","units":3,"type":"armor"]),
                   "buckler":(["file":COMMONFILE"armour/buckler","units":2,"type":"armor"]),
                   "boots":(["file":COMMONFILE"clothing/shoes","units":2]),
                   "cape":(["file":COMMONFILE"clothing/cloak","units":3]),
                   "coif":(["file":COMMONFILE"armour/coif_leather","units":2,"type":"armor"]),
                   "gauntlets":(["file":COMMONFILE"armour/leather_gauntlets","units":1,"type":"armor"]),
                   "giant holster":(["file":COMMONFILE"sheath/sheath_giantbludgeon","units":3,"type":"sheath"]),
                   "giant sheath":(["file":COMMONFILE"sheath/sheath_great","units":4,"type":"sheath"]),
                   "greaves":(["file":COMMONFILE"armour/leather_greaves","units":1,"type":"armor"]),
                   "hide":(["file":COMMONFILE"armour/hide_large","units":4,"type":"armor"]),
                   "large holster":(["file":COMMONFILE"sheath/sheath_lgbludgeon","units":3,"type":"sheath"]),
                   "large sheath":(["file":COMMONFILE"sheath/sheath_large","units":3,"type":"sheath"]),
                   "large sleeve":(["file":COMMONFILE"sheath/sheath_lgstaff","units":3,"type":"sheath"]),
                   "leather":(["file":COMMONFILE"armour/leather","units":3,"type":"armor"]),
                   "medium holster":(["file":COMMONFILE"sheath/sheath_mbludgeon","units":2,"type":"sheath"]),
                   "medium sheath":(["file":COMMONFILE"sheath/sheath_medium","units":2,"type":"sheath"]),
                   "medium sleeve":(["file":COMMONFILE"sheath/sheath_mstaff","units":2,"type":"sheath"]),
                   "padded":(["file":COMMONFILE"armour/padded","units":2,"type":"armor"]),
                   "shield strap":(["file":COMMONFILE"sheath/shieldstrap","units":2,"type":"sheath"]),
                   "small sheath":(["file":COMMONFILE"sheath/sheath_small","units":1,"type":"sheath"]),
                   "studded":(["file":COMMONFILE"armour/studded","units":3,"type":"armor"]),
                   "whip":(["file":COMMONFILE"weapon/whip","units":2,"type":"weapon"]),
                   "sling":(["file":COMMONFILE"lrweapon/sling","units":1,"type":"weapon"]),
                   ]);

mapping TAILOR = ([]);
TAILOR = ([
              "belt":(["file":COMMONFILE"clothing/belt","units":1]),
              "caparison":(["file":COMMONFILE"clothing/caparison","units":4]),
              "cloak":(["file":COMMONFILE"clothing/cloak","units":3]),
              "eyepatch":(["file":COMMONFILE"misc/eyepatch","units":1]),
              "gloves":(["file":COMMONFILE"clothing/gloves","units":1]),
              "hat":(["file":COMMONFILE"clothing/hat","units":2]),
              "breeches":(["file":COMMONFILE"clothing/breeches","units":3]),
              "pocket robe":(["file":COMMONFILE"clothing/magerobe","units":5]),
              "robe":(["file":COMMONFILE"clothing/robe","units":4]),
              "shirt":(["file":COMMONFILE"clothing/shirt","units":3]),
              "shoes":(["file":COMMONFILE"clothing/shoes","units":2]),
              "small sack":(["file":COMMONFILE"misc/ssack","units":2]),
              "large sack":(["file":COMMONFILE"misc/sack","units":6]),
              ]);

mapping JEWEL = ([]);
JEWEL = ([
             "anklet":(["file":COMMONFILE"jewelry/anklet","units":2]),
             "bracelet":(["file":COMMONFILE"jewelry/bracelet","units":2]),
             "bracers":(["file":COMMONFILE"armour/bracers","units":3]),
             "circlet":(["file":COMMONFILE"jewelry/circlet","units":2]),
             "necklace":(["file":COMMONFILE"jewelry/necklace","units":2]),
             "ring":(["file":COMMONFILE"jewelry/ring","units":2]),
             ]);

mapping WEAPONSMITH = ([]);
WEAPONSMITH = ([
                   "arquebus":(["file":COMMONFILE"lrweapon/arquebus","units":8]),
                   "pistol":(["file":COMMONFILE"lrweapon/pistol","units":4]),
                   "cannon":(["file":COMMONFILE"lrweapon/cannon","units":60]),
                   "musket":(["file":COMMONFILE"lrweapon/musket","units":9]),
                   "culverin":(["file":COMMONFILE"lrweapon/culverin","units":40]),
                   "hackbut":(["file":COMMONFILE"lrweapon/hackbut","units":18]),
                   "cartridge":(["file":COMMONFILE"lrweapon/cartridge","units":1]),
                   "grapeshot":(["file":COMMONFILE"lrweapon/grapeshot","units":1]),
                   "cannonball":(["file":COMMONFILE"lrweapon/cannonball","units":20]),
                   "bastard sword":(["file":COMMONFILE"weapon/bastard","units":3]),
                   "claw":(["file":COMMONFILE"weapon/claw","units":2]),
                   "double axe":(["file":COMMONFILE"weapon/double_axe","units":4]),
                   "double bladed sword":(["file":COMMONFILE"weapon/double_bladed_sword","units":4]),
                   "dwarven waraxe":(["file":COMMONFILE"weapon/dwarvenwaraxe","units":3]),
                   "elven curved blade":(["file":COMMONFILE"weapon/elvencurvedblade","units":4]),
                   "dagger":(["file":COMMONFILE"weapon/dagger","units":1]),
                   "estoc":(["file":COMMONFILE"weapon/estoc","units":3]),
                   "fan":(["file":COMMONFILE"weapon/fan","units":1]),
                   "falcata":(["file":COMMONFILE"weapon/falcata","units":3]),
                   "flail":(["file":COMMONFILE"weapon/flail","units":3]),
                   "giant axe":(["file":COMMONFILE"weapon/giant_battle_axe","units":5]),
                   "giant double axe":(["file":COMMONFILE"weapon/giant_double_axe","units":5]),
                   "giant double sword":(["file":COMMONFILE"weapon/giant_double_bladed_sword","units":5]),
                   "giant hammer":(["file":COMMONFILE"weapon/giant_hammer","units":5]),
                   "giant mace":(["file":COMMONFILE"weapon/giant_mace","units":5]),
                   "giant scythe":(["file":COMMONFILE"weapon/giant_scythe","units":5]),
                   "giant sword":(["file":COMMONFILE"weapon/giant_bastard","units":5]),
                   "kukri":(["file":COMMONFILE"weapon/kukri","units":1]),
                   "large axe":(["file":COMMONFILE"weapon/large_battle_axe","units":4]),
                   "large hammer":(["file":COMMONFILE"weapon/hammer_lg","units":4]),
                   "longsword":(["file":COMMONFILE"weapon/longsword","units":3]),
                   "mace":(["file":COMMONFILE"weapon/mace","units":3]),
                   "medium axe":(["file":COMMONFILE"weapon/battle_axe","units":3]),
                   "medium hammer":(["file":COMMONFILE"weapon/warhammer","units":3]),
                   "polearm":(["file":COMMONFILE"weapon/halberd","units":4]),
                   "rapier":(["file":COMMONFILE"weapon/rapier","units":2]),
                   "scimitar":(["file":COMMONFILE"weapon/scimitar","units":2]),
                   "scythe":(["file":COMMONFILE"weapon/scythe","units":3]),
                   "shurikens":(["file":COMMONFILE"lrweapon/shurikens","units":1]),
                   "darts":(["file":COMMONFILE"lrweapon/darts","units":1]),
                   "small hammer":(["file":COMMONFILE"weapon/hammer_sm","units":2]),
                   "two-handed sword":(["file":COMMONFILE"weapon/two_hand_sword","units":4]),
                   "small axe":(["file":COMMONFILE"weapon/handaxe","units":2]),
                   "shortsword":(["file":COMMONFILE"weapon/shortsword","units":2]),
                   "waveblade":(["file":COMMONFILE"weapon/waveblade","units":1]),
                   "wand":(["file":COMMONFILE"weapon/club","units":1,"type":"weapon"]),
                   ]);

mapping WOODWORK = ([]);
WOODWORK = ([
                "cane":(["file":COMMONFILE"weapon/club","units":1,"type":"weapon"]),
                "giant club":(["file":COMMONFILE"weapon/giant_club","units":5,"type":"weapon"]),
                "lance":(["file":COMMONFILE"weapon/hhlance","units":4,"type":"weapon"]),
                "large club":(["file":COMMONFILE"weapon/club_lg","units":4,"type":"weapon"]),
                "large spear":(["file":COMMONFILE"weapon/spear_lg","units":4,"type":"weapon"]),
                "medium club":(["file":COMMONFILE"weapon/mclub","units":3,"type":"weapon"]),
                "medium spear":(["file":COMMONFILE"weapon/mspear","units":3,"type":"weapon"]),
                "medium staff":(["file":COMMONFILE"weapon/mstaff","units":3,"type":"weapon"]),
                "nunchucks":(["file":COMMONFILE"weapon/nunchucks","units":1,"type":"weapon"]),
                "quarter staff":(["file":COMMONFILE"weapon/quarter_staff","units":4,"type":"weapon"]),
                "rod":(["file":COMMONFILE"weapon/club","units":1,"type":"weapon"]),
                "small club":(["file":COMMONFILE"weapon/club","units":2,"type":"weapon"]),
                "small spear":(["file":COMMONFILE"weapon/spear_sm","units":2,"type":"weapon"]),
                "small spear":(["file":COMMONFILE"weapon/sstaff","units":2,"type":"weapon"]),

                "crossbow":(["file":COMMONFILE"lrweapon/hcrossbow","units":3,"type":"lrweapon"]),
                "darts":(["file":COMMONFILE"lrweapon/darts","units":1,"type":"lrweapon"]),
                "long bow":(["file":COMMONFILE"lrweapon/longbow","units":3,"type":"lrweapon"]),
                "short bow":(["file":COMMONFILE"lrweapon/shortbow","units":2,"type":"lrweapon"]),

                "drums":(["file":COMMONFILE"instruments/drum","units":2,"type":"instrument"]),
                "flute":(["file":COMMONFILE"instruments/flute","units":1,"type":"instrument"]),
                "guitar":(["file":COMMONFILE"instruments/guitar","units":2,"type":"instrument"]),
                "lap-harp":(["file":COMMONFILE"instruments/lap-harp","units":2,"type":"instrument"]),
                "lute":(["file":COMMONFILE"instruments/lute","units":2,"type":"instrument"]),
                "lyre":(["file":COMMONFILE"instruments/lyre","units":2,"type":"instrument"]),
                "mandolin":(["file":COMMONFILE"instruments/mandolin","units":2,"type":"instrument"]),
                "pan pipes":(["file":COMMONFILE"instruments/panpipes","units":1,"type":"instrument"]),

                "shield":(["file":COMMONFILE"armour/mshield","units":2]),
                "tower shield":(["file":COMMONFILE"armour/shield","units":3]),

                "bolts":(["file":COMMONFILE"lrweapon/hquarrels","units":1,"type":"arrows"]),
                "flight arrows":(["file":COMMONFILE"lrweapon/flarrows","units":1,"type":"arrows"]),
                "sheath arrows":(["file":COMMONFILE"lrweapon/arrows","units":1,"type":"arrows"]),

                "carving":(["file":COMMONFILE"misc/carving","units":1,"type":"carving"]),
                "pipe":(["file":COMMONFILE"misc/pipe","units":1,"type":"carving"]),
                "wand":(["file":COMMONFILE"weapon/wand","units":1,"type":"weapon"]),
                "scroll case":(["file":COMMONFILE"misc/scroll_case","units":3,"type":"carving"]),
                ]);

#define CRAFT_TO_CHECK ([ "woodworker" : WOODWORK, "weaponsmith" : WEAPONSMITH, "jeweller" : JEWEL, \
                          "tailor" : TAILOR, "leatherworker" : LEATHERWORK, "armorsmith" : ARMORSMITH ])
