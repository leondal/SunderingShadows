//
// AC for clothing removed, added masks as clothing, some weights of armor tweaked to be more in line with items in game and units used *Styx*  9/28/03, last change 8/4/03
/* added breastplate to armor & eyeglasses to jeweling, also changed AC of robe, etc. down from 3 to 1 and made a couple of comparable ones 1 from 0 since they only get the AC if made from leather (per T) and a leather coat would protect as well as a robe or jacket.
   Also cut value of jewelry to 10% of what it was for balance, cut some weights, and increased units required for larger items for better proportion.
*Styx* 12/05/03, last change 9/28/03
*/

#define ARMOURS ([\
    "banded mail":(["price":200,"weight":45,"ac":6, "units":6, "material":"metal","limbs":({"torso"}),"type":"armor",]),\
    "brigandine":(["price":120,"weight":35,"ac":4, "units":5, "material":"metal","limbs":({"torso"}),"type":"armor",]),\
    "plate mail":(["price":900,"weight":55,"ac":7, "units":7, "material":"metal","limbs":({"torso"}),"type":"armor",]),\
    "chain mail":(["price":75,"weight":40,"ac":5, "units":5, "material":"metal","limbs":({"torso"}),"type":"chain",]),\
    "field plate":(["price":2000,"weight":60,"ac":8, "units":8, "material":"metal","limbs":({"torso"}),"type":"armor",]),\
    "full plate":(["price":6000,"weight":70,"ac":9, "units":9, "material":"metal","limbs":({"torso"}),"type":"armor",]),\
    "ring mail":(["price":100,"weight":30,"ac":3, "units":3, "material":"metal","limbs":({"torso"}),"type":"armor",]),\
    "splint mail":(["price":80,"weight":50,"ac":7, "units":7, "material":"metal","limbs":({"torso"}),"type":"armor",]),\
    "scale mail":(["price":120,"weight":40,"ac":4, "units":4, "material":"metal","limbs":({"torso"}),"type":"armor",]),\
    "leather":(["price":5,"weight":10,"ac":2, "units":2, "material":"leather","limbs":({"torso"}),"type":"leather",]),\
    "studded leather":(["price":20,"weight":25,"ac":4, "units":4, "material":"leather","limbs":({"torso"}),"type":"leather",]),\
    "padded leather":(["price":4,"weight":10,"ac":2, "units":2, "material":"leather","limbs":({"torso"}),"type":"leather",]),\
    "helmet":(["price":30,"weight":3,"ac":1, "units":2, "material":"metal","limbs":({"head"}),"type":"armor",]),\
    "leather coif":(["price":10,"weight":3,"ac":1, "units":1, "material":"leather","limbs":({"head"}),"type":"leather",]),\
    "chain coif":(["price":25,"weight":3,"ac":1, "units":1, "material":"metal","limbs":({"head"}),"type":"chain",]),\
    "shield":(["price":3,"weight":8,"ac":1, "units":1, "material":"metal","limbs":({"right hand"}),"type":"shield",]),\
    "body shield":(["price":20,"weight":10,"ac":2, "units":2, "material":"metal","limbs":({"right hand"}),"type":"shield",]),\
    "gauntlets":(["price":10,"weight":5,"ac":1, "units":1, "material":"metal","limbs":({"left hand","right hand"}),"type":"armor",]),\
"leather gauntlets":(["price":10,"weight":3,"ac":1, "units":1, "material":"leather","limbs":({"left hand","right hand"}),"type":"leather",]),\
    "greaves":(["price":10,"weight":5,"ac":1, "units":1, "material":"metal","limbs":({"left leg","right leg"}),"type":"armor",]),\
"leather greaves":(["price":10,"weight":3,"ac":1, "units":1, "material":"leather","limbs":({"left leg","right leg"}),"type":"leather",]),\
    "breastplate":(["price":500,"weight":25,"ac":4, "units":3, "material":"metal","limbs":({"torso"}),"type":"armor",]),\
])

#define CLOTHINGS ([ \
    "hat":(["price":5,"weight":1,"ac":0, "units":1,"limbs":({"head"})]),\
    "turban":(["price":8,"weight":1,"ac":0, "units":1, "limbs":({"head"})]),\
    "hood":(["price":5,"weight":1,"ac":0, "units":1, "limbs":({"head"})]),\
    "bandanna":(["price":4,"weight":1,"ac":0, "units":1, "limbs":({"head"})]),\
    "mask":(["price":5,"weight":1,"ac":0, "units":1, "limbs":({"head"})]),\
    "ribbons":(["price":3,"weight":1,"ac":0, "units":1, "limbs":({"head"})]),\
    "scarf":(["price":5,"weight":1,"ac":0, "units":1, "limbs":({"neck"})]),\
    "shawl":(["price":20,"weight":2,"ac":0, "units":2,"limbs":({"neck"})]),\
    "cloak":(["price":20,"weight":7,"ac":1, "units":3,"limbs":({"neck"})]),\
    "cape":(["price":15,"weight":6,"ac":1, "units":3,"limbs":({"neck"})]),\
    "coat":(["price":30,"weight":7,"ac":1, "units":4,"limbs":({"neck"})]),\
    "jacket":(["price":80,"weight":6,"ac":1, "units":3, "limbs":({"torso"})]),\
    "sweater":(["price":65,"weight":5,"ac":0, "units":3, "limbs":({"torso"})]),\
    "robe":(["price":30,"weight":7,"ac":1, "units":5, "limbs":({"torso"})]),\
    "gown":(["price":100,"weight":7,"ac":0, "units":5, "limbs":({"torso"})]),\
    "dress":(["price":60,"weight":6,"ac":0, "units":5, "limbs":({"torso"})]),\
    "surcoat":(["price":50,"weight":6,"ac":1, "units":3, "limbs":({"torso"})]),\
    "tabard":(["price":5,"weight":4,"ac":0, "units":1, "limbs":({"torso"})]),\
    "toga":(["price":15,"weight":5,"ac":0, "units":3, "limbs":({"torso"})]),\
    "blouse":(["price":40,"weight":8,"ac":0, "units":4, "limbs":({"torso"})]),\
    "jerkin":(["price":30,"weight":7,"ac":1, "units":4, "limbs":({"torso"})]),\
    "tunic":(["price":20,"weight":4,"ac":1, "units":3, "limbs":({"torso"})]),\
    "shirt":(["price":15,"weight":3,"ac":1, "units":3, "limbs":({"torso"})]),\
    "vest":(["price":10,"weight":3,"ac":0, "units":2, "limbs":({"torso"})]),\
    "girdle":(["price":9,"weight":3,"ac":0, "units":2, "limbs":({"torso"})]),\
    "sash":(["price":5,"weight":1,"ac":0, "units":1, "limbs":({"waist"})]),\
    "belt":(["price":3,"weight":2,"ac":0, "units":1, "limbs":({"waist"})]),\
    "skirt":(["price":9,"weight":2,"ac":0, "units":3, "limbs":({"waist"})]),\
    "kilt":(["price":8,"weight":2,"ac":0, "units":3, "limbs":({"waist"})]),\
    "loincloth":(["price":3,"weight":2,"ac":0, "units":3, "limbs":({"waist"})]),\
    "shorts":(["price":10,"weight":3,"ac":0, "units":2, "limbs":({"right leg", "left leg"})]),\
    "pants":(["price":15,"weight":4,"ac":0, "units":3, "limbs":({"right leg", "left leg"})]),\
    "overalls":(["price":15,"weight":5,"ac":0, "units":4, "limbs":({"right leg", "left leg"})]),\
    "hose":(["price":10,"weight":1,"ac":0, "units":2, "limbs":({"right leg", "left leg"})]),\
    "leggings":(["price":12,"weight":1,"ac":0, "units":2, "limbs":({"right leg", "left leg"})]),\
    "tights":(["price":12,"weight":1,"ac":0, "units":2, "limbs":({"right leg", "left leg"})]),\
    "shoes":(["price":10,"weight":2,"ac":0, "units":1, "limbs":({"left foot","right foot"})]),\
    "sandals":(["price":5,"weight":2,"ac":0, "units":1, "limbs":({"left foot","right foot"})]),\
    "boots":(["price":10,"weight":3,"ac":0, "units":2, "limbs":({"left foot","right foot"})]),\
    "riding boots":(["price":15,"weight":6,"ac":1, "units":2, "limbs":({"left foot","right foot"})]),\
    "gloves":(["price":15,"weight":1,"ac":0, "units":1, "limbs":({"left hand","right hand"})]),\
    "mittens":(["price":3,"weight":1,",ac":0, "units":1, "limbs":({"left hand","right hand"})])\
])

#define WEAPONS ([\
    "battle axe":(["wc#":1,"wcdice":8,"lwc#":1,"lwcdice":8, "size":({1,2,3,4}),]),\
    "club":(["wc#":1,"wcdice":6,"lwc#":1,"lwcdice":3, "size":({1,2,3,4}),]),\
    "dagger":(["wc#":1,"wcdice":4,"lwc#":1,"lwcdice":3, "size":({1}),]),\
    "dirk":(["wc#":1,"wcdice":4,"lwc#":1,"lwcdice":3, "size":({1}),]),\
    "footman's flail":(["wc#":1,"wcdice":7,"lwc#":2,"lwcdice":4, "size":({2}),]),\
    "footman's mace":(["wc#":1,"wcdice":7,"lwc#":1,"lwcdice":6, "size":({2}),]),\
    "footman's pick":(["wc#":1,"wcdice":7,"lwc#":2,"lwcdice":4, "size":({2}),]),\
    "hand axe":(["wc#":1,"wcdice":7,"lwc#":2,"lwcdice":4, "size":({1,2,3}),]),\
    "horseman's flail":(["wc#":1,"wcdice":5,"lwc#":1,"lwcdice":5, "size":({2}),]),\
    "horseman's mace":(["wc#":1,"wcdice":6,"lwc#":1,"lwcdice":4, "size":({2}),]),\
    "horseman's pick":(["wc#":1,"wcdice":5,"lwc#":1,"lwcdice":4, "size":({2}),]),\
    "knife":(["wc#":1,"wcdice":3,"lwc#":1,"lwcdice":2, "size":({1,2}),]),\
    "morning star":(["wc#":2,"wcdice":4,"lwc#":1,"lwcdice":7, "size":({2,3}),]),\
    "mace":(["wc#":2,"wcdice":4,"lwc#":1,"lwcdice":7, "size":({2,3,4}),]),\
    "quarterstaff":(["wc#":1,"wcdice":6,"lwc#":1,"lwcdice":6, "size":({2,3,4}),]),\
    "scourge":(["wc#":1,"wcdice":4,"lwc#":1,"lwcdice":2, "size":({2,3,4}),]),\
    "scythe":(["wc#":1,"wcdice":8,"lwc#":1,"lwcdice":10, "size":({2,3,4}),]),\
    "spear":(["wc#":1,"wcdice":6,"lwc#":1,"lwcdice":8, "size":({1,2,3,4}),]),\
    "trident":(["wc#":1,"wcdice":7,"lwc#":3,"lwcdice":4, "size":({2,3,4}),]),\
    "warhammer":(["wc#":1,"wcdice":5,"lwc#":1,"lwcdice":4, "size":({1,2,3,4}),]),\
    "whip":(["wc#":1,"wcdice":6,"lwc#":1,"lwcdice":6, "size":({2,3,4}),]),\
    "bardiche":(["wc#":2,"wcdice":4,"lwc#":2,"lwcdice":6, "size":({2,3,4}),]),\
    "fauchard":(["wc#":1,"wcdice":6,"lwc#":1,"lwcdice":8, "size":({2,3,4}),]),\
    "glaive":(["wc#":1,"wcdice":6,"lwc#":1,"lwcdice":10, "size":({2,3,4}),]),\
    "halberd":(["wc#":1,"wcdice":10,"lwc#":2,"lwcdice":6, "size":({2,3,4}),]),\
    "lucern hammer":(["wc#":2,"wcdice":4,"lwc#":1,"lwcdice":6, "size":({2,3,4}),]),\
    "partisan":(["wc#":1,"wcdice":6,"lwc#":1,"lwcdice":7, "size":({2,3,4}),]),\
    "one-handed bastard sword":(["wc#":1,"wcdice":8,"lwc#":1,"lwcdice":12, "size":({2}),]),\
    "two-handed bastard sword":(["wc#":2,"wcdice":4,"lwc#":2,"lwcdice":8, "size":({2,3}),]),\
    "broad sword":(["wc#":2,"wcdice":4,"lwc#":2,"lwcdice":5, "size":({1,2,3,4}),]),\
    "khopesh":(["wc#":2,"wcdice":4,"lwc#":2,"lwcdice":5, "size":({2,3,4}),]),\
    "long sword":(["wc#":1,"wcdice":8,"lwc#":1,"lwcdice":12, "size":({2}),]),\
    "scimitar":(["wc#":1,"wcdice":8,"lwc#":1,"lwcdice":12, "size":({2}),]),\
    "short sword":(["wc#":2,"wcdice":3,"lwc#":2,"lwcdice":4, "size":({1}),]),\
    "two-handed sword":(["wc#":3,"wcdice":4,"lwc#":3,"lwcdice":6, "size":({3,4}),]),\
    "rapier":(["wc#":2,"wcdice":3,"lwc#":2,"lwcdice":4, "size":({2}),]),\
    "light rapier":(["wc#":1,"wcdice":5,"lwc#":1,"lwcdice":5, "size":({1}),]),\
    "claw":(["wc#":1,"wcdice":5,"lwc#":1,"lwcdice":4, "size":({1}),]),\
    "fan":(["wc#":1,"wcdice":5,"lwc#":1,"lwcdice":3, "size":({1}),]),\
    "katana":(["wc#":3,"wcdice":6,"lwc#":3,"lwcdice":6, "size":({3,4}),]),\
    "whip dagger":(["wc#":1,"wcdice":8,"lwc#":1,"lwcdice":8, "size":({2,3,4}),]),\
    "sickle":(["wc#":1,"wcdice":4,"lwc#":1,"lwcdice":4, "size":({1}),]),\
    "pick":(["wc#":1,"wcdice":6,"lwc#":2,"lwcdice":3, "size":({1}),]),\
])   

#define LANCES ([\
    "heavy horse lance":(["wc#":1,"wcdice":9,"lwc#":3,"lwcdice":6, "size":({1,2,3,4}),]),\
    "light horse lance":(["wc#":1,"wcdice":6,"lwc#":1,"lwcdice":8, "size":({1,2,3,4}),]),\
    "jousting lance":(["wc#":1,"wcdice":2,"lwc#":1,"lwcdice":1, "size":({1,2,3,4}),]),\
    "medium horse lance":(["wc#":1,"wcdice":7,"lwc#":2,"lwcdice":6, "size":({1,2,3,4}),]),\
])

#define WEAPON_BASICS ([\
    "battle axe":(["price":4,"weight":7, "type":"slashing","prof":"axe",]),\
    "club":(["price":1,"weight":3, "type":"magebludgeon","prof":"club",]),\
    "dagger":(["price":1,"weight":2, "type":"magepiercing","prof":"blades",]),\
    "dirk":(["price":1,"weight":2, "type":"magepiercing","prof":"blades",]),\
    "footman's flail":(["price":4,"weight":15, "type":"bludgeon","prof":"flail",]),\
    "footman's mace":(["price":4,"weight":2, "type":"bludgeon","prof":"mace",]),\
    "hand axe":(["price":2,"weight":5, "type":"piercing","prof":"axe",]),\
    "horseman's flail":(["price":5,"weight":15, "type":"bludgeon","prof":"flail",]),\
    "horseman's mace":(["price":6,"weight":2, "type":"bludgeon","prof":"mace",]),\
    "horseman's pick":(["price":5,"weight":2, "type":"piercing","prof":"pick",]),\
    "knife":(["price":1,"weight":2, "type":"magepiercing","prof":"blades",]),\
    "morning star":(["price":8,"weight":12, "type":"bludgeon","prof":"mace",]),\
    "mace":(["price":6,"weight":10, "type":"bludgeon","prof":"mace",]),\
    "quarterstaff":(["price":2,"weight":4, "type":"magebludgeon","prof":"staff",]),\
    "rapier" : (["price":15,"weight":4,"type":"thiefpiercing","prof":"rapier",]),\
    "light rapier" : (["price":8,"weight":3,"type":"thiefpiercing","prof":"rapier",]),\
    "scourge":(["price":3,"weight":2, "type":"lash","prof":"whip",]),\
    "scythe":(["price":2,"weight":7, "type":"slashing","prof":"polearm",]),\
    "spear":(["price":2,"weight":5, "type":"piercing","prof":"spear",]),\
    "trident":(["price":5,"weight":8, "type":"piercing","prof":"spear",]),\
    "warhammer":(["price":14,"weight":10, "type":"bludgeon","prof":"hammer",]),\
    "whip":(["price":1,"weight":2, "type":"lash","prof":"whip",]),\
    "bardiche":(["price":8,"weight":10, "type":"slashing","prof":"axe",]),\
    "fauchard":(["price":6,"weight":7, "type":"slashing","prof":"polearm",]),\
    "glaive":(["price":8,"weight":12, "type":"slashing","prof":"polearm",]),\
    "halberd":(["price":7,"weight":10, "type":"slashing","prof":"polearm",]),\
    "lucern hammer":(["price":5,"weight":10, "type":"bludgeon","prof":"hammer",]),\
    "partisan":(["price":5,"weight":10, "type":"piercing","prof":"polearm",]),\
    "one-handed bastard sword":(["price":10,"weight":10, "type":"slashing","prof":"blades",]),\
    "two-handed bastard sword":(["price":15,"weight":10, "type":"slashing","prof":"blades",]),\
    "broad sword":(["price":10,"weight":5, "type":"slashing","prof":"medium blades",]),\
    "khopesh":(["price":9,"weight":7, "type":"thiefslashing","prof":"blades",]),\
    "long sword":(["price":15,"weight":7, "type":"thiefslashing","prof":"blades",]),\
    "scimitar":(["price":15,"weight":4, "type":"thiefslashing","prof":"blades",]),\
    "short sword":(["price":7,"weight":4, "type":"thiefslashing","prof":"short blades",]),\
    "two-handed sword":(["price":20,"weight":12, "type":"slashing","prof":"blades",]),\
    "claw":(["price":10,"weight":5, "type":"thiefslashing","prof":"knuckles",]),\
    "fan":(["price":25,"weight":3, "type":"magepiercing","prof":"fan",]),\
    "katana":(["price":60,"weight":12, "type":"slashing","prof":"blades",]),\
    "whip dagger":(["price":15,"weight":4, "type":"magepiercing","prof":"whip",]),\
    "sickle":(["price":5,"weight":3, "type":"magepiercing","prof":"blades",]),\
    "pick":(["price":15,"weight":4, "type":"thiefpiercing","prof":"short blades",]),\
])

#define LANCES_BASICS ([\
    "heavy horse lance":(["price":3,"weight":2,"materials":({"wood","metal"}), "units":({1,1}), "type":"piercing",]),\
    "light horse lance":(["price":3,"weight":2,"materials":({"wood","metal"}), "units":({1,1}), "type":"piercing",]),\
    "jousting lance":(["price":3,"weight":2,"materials":({"wood","metal"}), "units":({1,1}), "type":"piercing",]),\
    "medium horse lance":(["price":3,"weight":2,"materials":({"wood","metal"}), "units":({1,1}), "type":"piercing",]),\
])

#define WEAPON_MATERIALS ([\
  "battle axe":(["materials":({"wood","metal"}), "units":({1,2}),]),\
  "club":(["materials":({"wood"}), "units":({1}),]),\
  "dagger":(["materials":({"metal"}), "units":({1}),]),\
  "dirk":(["materials":({"metal"}), "units":({1}),]),\
  "footman's flail":(["materials":({"wood","metal"}), "units":({1,1}),]),\
  "footman's mace":(["materials":({"wood","metal"}), "units":({1,1}),]),\
  "footman's pick":(["materials":({"wood","metal"}), "units":({1,1}),]),\
  "hand axe":(["materials":({"wood","metal"}), "units":({1,1}),]),\
  "horseman's flail":(["materials":({"wood","metal"}), "units":({1,1}),]),\
  "horseman's mace":(["materials":({"wood","metal"}), "units":({1,1}),]),\
  "horseman's pick":(["materials":({"wood","metal"}), "units":({1,1}),]),\
  "knife":(["materials":({"wood","metal"}), "units":({1,1}),]),\
  "morning star":(["materials":({"wood","metal"}), "units":({1,2})]),\
  "mace":(["materials":({"wood","metal"}), "units":({1,1}),]),\
  "quarterstaff":(["materials":({"wood"}), "units":({2}),]),\
  "scourge":(["materials":({"wood","metal"}), "units":({1,1}),]),\
  "scythe":(["materials":({"wood","metal"}), "units":({3,1}),]),\
  "spear":(["materials":({"wood","metal"}), "units":({3,1}),]),\
  "trident":(["materials":({"wood","metal"}), "units":({2,1}),]),\
  "warhammer":(["materials":({"wood","metal"}), "units":({1,3}),]),\
  "whip":(["materials":({"leather"}), "units":({2}),]),\
  "bardiche":(["materials":({"wood","metal"}), "units":({3,1}),]),\
  "fauchard":(["materials":({"wood","metal"}), "units":({3,1}),]),\
  "glaive":(["materials":({"wood","metal"}), "units":({3,1}),]),\
  "halberd":(["materials":({"wood","metal"}), "units":({3,1}),]),\
  "lucern hammer":(["materials":({"wood","metal"}), "units":({3,1}),]),\
  "partisan":(["materials":({"wood","metal"}), "units":({3,1}),]),\
  "rapier" : (["materials":({"metal"}), "units":({2}),]),\
  "one-handed bastard sword":(["materials":({"metal"}), "units":({2}),]),\
  "two-handed bastard sword":(["materials":({"metal"}), "units":({3}),]),\
  "broad sword":(["materials":({"metal"}), "units":({1}),]),\
  "khopesh":(["materials":({"metal"}), "units":({2}),]),\
  "long sword":(["materials":({"metal"}), "units":({2}),]),\
  "scimitar":(["materials":({"metal"}), "units":({2}),]),\
  "short sword":(["materials":({"metal"}), "units":({1}),]),\
  "two-handed sword":(["materials":({"metal"}), "units":({3}),]),\
  "light rapier":(["materials":({"metal"}), "units":({1}),]),\
  "claw":(["materials":({"metal"}), "units":({1}),]),\
  "fan":(["materials":({"metal"}), "units":({1}),]),\
  "sickle":(["materials":({"metal","wood"}), "units":({1,1}),]),\
  "katana":(["materials":({"metal"}), "units":({3}),]),\
  "whip dagger":(["materials":({"metal","leather"}), "units":({1,2}),]),\
  "pick":(["materials":({"metal"}), "units":({1}),]),\
])

#define LANCE_MATERIALS ([\
  "heavy horse lance":(["price":3,"weight":2,"materials":({"wood","metal"}), "units":({1,1}), "type":"piercing",]),\
  "light horse lance":(["price":3,"weight":2,"materials":({"wood","metal"}), "units":({1,1}), "type":"piercing",]),\
  "jousting lance":(["price":3,"weight":2,"materials":({"wood","metal"}), "units":({1,1}), "type":"piercing",]),\
  "medium horse lance":(["price":3,"weight":2,"materials":({"wood","metal"}), "units":({1,1}), "type":"piercing",]),\
])

#define JEWELRY ([\
    "tiara":(["price":70,"weight":4,"ac":0, "units":2, "limbs":({"head"})]),\
    "crown":(["price":90,"weight":5,"ac":0, "units":3, "limbs":({"head"})]),\
    "circlet":(["price":60,"weight":3,"ac":0, "units":2, "limbs":({"head"})]),\
    "coronet":(["price":80,"weight":3,"ac":0, "units":2, "limbs":({"head"})]),\
    "coiffe":(["price":60,"weight":2,"ac":0, "units":2, "limbs":({"head"})]),\
    "diadem":(["price":75,"weight":3,"ac":0, "units":2, "limbs":({"head"})]),\
    "comb":(["price":30,"weight":2,"ac":0, "units":1, "limbs":({"head"})]),\
    "earring":(["price":7,"weight":1,"ac":0, "units":1, "limbs":({"head"})]),\
    "eyeglasses":(["price":50,"weight":1,"ac":0, "units":1, "limbs":({"head"})]),\
    "monocle":(["price":30,"weight":1,"ac":0, "units":1, "limbs":({"head"})]),\
    "necklace":(["price":60,"weight":2,"ac":0, "units":1, "limbs":({"neck"})]),\
    "pendant":(["price":50,"weight":2,"ac":0, "units":1, "limbs":({"neck"})]),\
    "amulet":(["price":30,"weight":2,"ac":0, "units":1, "limbs":({"neck"})]),\
    "locket":(["price":45,"weight":2,"ac":0, "units":1, "limbs":({"neck"})]),\
    "medallion":(["price":25,"weight":2,"ac":0, "units":1, "limbs":({"neck"})]),\
    "choker":(["price":25,"weight":2,"ac":0, "units":1, "limbs":({"neck"})]),\
    "collar":(["price":30,"weight":2,"ac":0, "units":1, "limbs":({"neck"})]),\
    "torque":(["price":35,"weight":4,"ac":0, "units":2, "limbs":({"neck"})]),\
    "clasp":(["price":50,"weight":2,"ac":0, "units":1, "limbs":({"torso"})]),\
    "brooch":(["price":60,"weight":2,"ac":0, "units":1, "limbs":({"torso"})]),\
    "pin":(["price":40,"weight":2,"ac":0, "units":1, "limbs":({"torso"})]),\
    "ring":(["price":45,"weight":2,"ac":0, "units":1, "limbs":({"right hand"})]),\
    "band":(["price":45,"weight":2,"ac":0, "units":1, "limbs":({"right hand"})]),\
    "bracelet":(["price":50,"weight":3,"ac":0, "units":2, "limbs":({"left arm"})]),\
    "bangle":(["price":30,"weight":2,"ac":0, "units":2, "limbs":({"left arm"})]),\
    "bracer":(["price":1000,"weight":8,"ac":0, "units":4, "limbs":({"left arm"})]),\
    "armband":(["price":80,"weight":3,"ac":0, "units":2, "limbs":({"left arm"})]),\
    "cufflink":(["price":30,"weight":2,"ac":0, "units":2, "limbs":({"left arm"})]),\
    "anklet":(["price":40,"weight":2,"ac":0, "units":2, "limbs":({"left leg"})]),\
    "headband":(["price":20,"weight":2,"ac":0, "units":2, "limbs":({"head"})]),\
])
