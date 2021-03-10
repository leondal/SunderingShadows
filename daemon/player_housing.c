#include <std.h>

/**
 * @file
 * @brief Helper functions for player houses
 *
 *
 */

/**
 * function to standardize tp proof levels across player houses, six levels available
 */
int get_phouse_tp_proof(string tpprooflevel)
{
    int tp_proof_dc, base_tp_proof_dc;
    base_tp_proof_dc = 13; //this base tp proof/poor DC
    tp_proof_dc = base_tp_proof_dc;
    if (!stringp(tpprooflevel) || tpprooflevel == "" || tpprooflevel == " ") {
        tpprooflevel = "common";
    }
    tpprooflevel = lower_case(tpprooflevel);
    switch (tpprooflevel) {
    case "poor":
        tp_proof_dc += 0;
        break;

    case "common":
        tp_proof_dc += 10;
        break;

    case "good":
        tp_proof_dc += 20;
        break;

    case "rare":
        tp_proof_dc += 30;
        break;

    case "epic":
        tp_proof_dc += 40;
        break;

    case "legendary":
        tp_proof_dc += 50;
        break;

    default:
        tp_proof_dc += 0;
        break;
    }
    return tp_proof_dc;
}

/**
 * function to standardize scry proof levels across player houses, six levels available
 */
int get_phouse_scry_proof(string scryprooflevel)
{
    int scry_proof_dc, base_scry_proof_dc;
    base_scry_proof_dc = 13;
    scry_proof_dc = base_scry_proof_dc;
    if (!stringp(scryprooflevel) || scryprooflevel == "" || scryprooflevel == " ") {
        scryprooflevel = "common";
    }
    scryprooflevel = lower_case(scryprooflevel);
    switch (scryprooflevel) {
    case "poor":
        scry_proof_dc += 0;
        break;

    case "common":
        scry_proof_dc += 10;
        break;

    case "good":
        scry_proof_dc += 20;
        break;

    case "rare":
        scry_proof_dc += 30;
        break;

    case "epic":
        scry_proof_dc += 40;
        break;

    case "legendary":
        scry_proof_dc += 50;
        break;

    default:
        scry_proof_dc += 0;
        break;
    }
    return scry_proof_dc;
}

int get_phouse_lock_dc(string locklevel) //function to standardize lock levels across player houses, six levels available
{
    int lockdc, baselockdc;
    baselockdc = 25; //this is a poor quality lock
    lockdc = baselockdc; //probably redundant, but I'm paranoid
    if (!stringp(locklevel) || locklevel == "" || locklevel == " ") {
        locklevel = "average";
    }
    locklevel = lower_case(locklevel);
    switch (locklevel) {
    case "poor":
        lockdc += 0;
        break;

    case "common":
        lockdc += 10;
        break;

    case "good":
        lockdc += 20;
        break;

    case "rare":
        lockdc += 30;
        break;

    case "epic":
        lockdc += 40;
        break;

    case "legendary":
        lockdc += 50;
        break;

    default:
        lockdc += 0;
        break;
    }
    return lockdc;
}

remove()
{
    destruct(this_object());
}
