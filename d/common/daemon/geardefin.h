/*  NOTES -
Common definitions for random gear generator for mobs 
/d/common/daemon/randgear_d

The daemon thus provides a means to magically enchant (up to +3) basic
gear and maintain consistency with damage, profs, weight etc. to the 
established bases as well as saving memory by using the same base files to
scatter more variety in lower level magical gear around.

********* NOTE ***********
Be SURE to add any new arrays to the mapping in the randgear daemon(s)
Do NOT remove or rename any of them but adding to or re-arranging the mix is fine.
**************************
*/
//Added some of the newer weapons - Cythera 5/07

#define EDGEDS ({"dagger", "dagger", "dagger", "shortsword", \
"shortsword", "knife", "spear_sm", "handaxe", "handaxe", \
"light_rapier", "sickle", "fan", "claw","wakizashi"})
#define EDGEDM ({"longsword", "bastard", "bastard", "battle_axe", \
"battle_axe", "broad", "mspear", "rapier", "scimitar", \
"trident", "khopesh", "whip_dagger"}) 
#define EDGEDL ({"bastard_two", "bastard_two", "bastard_two", "bardiche", \
"bardiche", "two_hand_sword", "two_hand_sword", \
"katana", "spear_lg"})

#define POLEARM ({"bill-guisarme", "fauchard", "glaive", "guisarme", \
"halberd",  "partisan", "voulge", "lucern_hammer", "spear_lg", \
"spear_lg", "scythe"})

#define CLUBM ({"scourge", "mclub", "mclub", "warhammer", "whip"})
#define BLUNTS ({"club", "hammer_sm" })
#define BLUNTM ({"mace", "flail", "flail", "scourge", "warhammer", "warhammer",\
"mclub", "morningstar", "morningstar", "mstaff"})
#define BLUNTL ({"quarter_staff", "quarter_staff", "hammer_lg", "hammer_lg", "club_lg" })
#define TOOL ({"pick", "sickle", "trident", "military_fork", "scythe" })

//note - forks & scythe included with TOOL group since they are't common either
//trident, military fork, & scythe

#define ARMORLT ({"padded", "leather", "leather", "studded", "studded", "hide" })
#define ARMORNP ({ "ring", "chain", "chain", "chain", "banded", "scale" })
#define ARMORPL ({ "bronze", "plate", "plate", "field", "field", "fullplate" })
#define ARMORCL ({ "robe" })
#define SHIELD ({ "buckler", "mshield", "shield", "sshield" }) 

//I had these below at first but decided the names were too hard to remember so I changed them to above.  Need to leave this in case anyone used them though.
