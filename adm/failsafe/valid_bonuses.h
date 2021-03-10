//Doing it this way per garrett's suggestion - this way, if somewhere down the
//road we want specific bonuses to only work on specific types of 
//equipment/items - Saide - June 2008
//shieldMiss added by ~Circe~ 2/28/13 to support new shield function.
#define VALID_ARMOR_BONUSES ({ \
    "ac bonus", \
    "attack bonus", \
    "damage bonus", \
    "sight bonus", \
    "magic resistance", \
    "empowered", \
    "spell penetration", \
    "skill bonus", \
    "bonus_spell_slots", \
    "bonus_spell_slots_1", \
    "bonus_spell_slots_2", \
    "bonus_spell_slots_3", \
    "bonus_spell_slots_4", \
    "bonus_spell_slots_5", \
    "bonus_spell_slots_6", \
    "bonus_spell_slots_7", \
    "bonus_spell_slots_8", \
    "bonus_spell_slots_9", \
    "shieldMiss", \
    "fire resistance", \
    "cold resistance", \
    "water resistance", \
    "air resistance", \
    "earth resistance", \
    "bludgeoning resistance", \
    "piercing resistance", \
    "slashing resistance", \
    "silver resistance", \
    "cold iron resistance", \
    "electricity resistance", \
    "acid resistance", \
    "sonic resistance", \
    "positive energy resistance", \
    "negative energy resistance", \
    "force resistance", \
    "divine resistance", \
    "untyped resistance", \
    "mental resistance", \
    "light resistance", \
    "darkness resistance", \
    "nature resistance", \
    "fire resistance percent", \
    "cold resistance percent", \
    "water resistance percent", \
    "air resistance percent", \
    "earth resistance percent", \
    "bludgeoning resistance percent", \
    "piercing resistance percent", \
    "slashing resistance percent", \
    "silver resistance percent", \
    "cold iron resistance percent", \
    "electricity resistance percent", \
    "acid resistance percent", \
    "sonic resistance percent", \
    "positive energy resistance percent", \
    "negative energy resistance percent", \
    "force resistance percent", \
    "divine resistance percent", \
    "untyped resistance percent", \
    "mental resistance percent", \
    "light resistance percent", \
    "darkness resistance percent", \
    "nature resistance percent", \
})

#define VALID_WEAPON_BONUSES ({ })

#define VALID_OTHER_BONUSES ({ })

#define VALID_BONUSES (VALID_ARMOR_BONUSES + VALID_WEAPON_BONUSES + VALID_OTHER_BONUSES)