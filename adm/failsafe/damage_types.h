// Whenever a new type is added, we need to add it to the following places..
//
// /adm/include/damage_types.h    for the damage type itself
// /adm/include/valid_bonuses.h   for the resistances to the damage (both resistance, and resistance percent)
// /std/Object.c                  for the item properties so they can be tracked on items wear/remove

#define VALID_DAMAGE_TYPES ({ \
    "fire", \
    "cold", \
    "water", \
    "air", \
    "earth", \
    "bludgeoning", \
    "piercing", \
    "slashing", \
    "silver", \
    "cold iron", \
    "electricity", \
    "acid", \
    "sonic", \
    "positive energy", \
    "negative energy", \
    "force", \
    "divine", \
    "untyped", \
    "darkness", \
    "light", \
    "mental", \
    "nature", \
    })