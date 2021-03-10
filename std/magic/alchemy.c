/**
 * @file
 * @brief This file references common alchemy subroutines, such as component cost and others.
 * Include it or reference it as an object.
 */


/*
   ardorite
   solumite
   imberol
   aurol
   noxiil
   vitriil
   sideriil
 */
int* name_to_components(string name)
{
    return map_array(explode(crypt(name, "$1$")[4..10], ""), (: atoi(sprintf("%d", $1[0])) % 2 :));
}
