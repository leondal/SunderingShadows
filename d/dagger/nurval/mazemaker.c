#include <std.h>

string seed;
int shift = 0;

string make_entropy()
{
    return crypt(random(1024)+"","$6$")[4..];
}

set_seed(string ss)
{
    shift = 0;
    seed = ss;
}

int random(int x)
{
    int res;

    if (!sizeof(seed)) {
        res = efun::random(x);
    } else {
        shift++;
        shift = shift > sizeof(seed) ? 0 : shift;
        res = seed[shift] % x;
    }

    return res;
}

mixed *alloc_maze(int size_a, int size_b)
{
    mixed * mze;
    int i;

    mze = allocate(size_a, ({}));

    for (i = 0; i < size_a; i++ )
    {
        mze[i] = allocate(size_b, ({}));
    }

    return mze;

}

connect_points(mixed *mze, int *a, int *b)
{
    int size_a = sizeof(mze), size_b = sizeof(mze[0]);

    if (a[0] < 0 || a[0] >= size_a || a[1] < 0 || a[1] >= size_b) {
        return;
    }
    if (b[0] < 0 || b[0] >= size_a || b[1] < 0 || b[1] >= size_b) {
        return;
    }

    if (has_point(a, mze[b[0]][b[1]])) {
        return;
    }

    mze[a[0]][a[1]] += ({({b[0], b[1]})});
    mze[b[0]][b[1]] += ({({a[0], a[1]})});
}

// member_array() fails on array membership
int has_point(int *a, mixed *arr)
{
    int *elem;

    if (!sizeof(arr)) {
        return 0;
    }

    foreach(elem in arr) {
        if (a[0] == elem[0] && a[1] == elem[1]) {
            return 1;
        }
    }
    return 0;
}

mixed *all_neighbors(mixed *mze, int *a)
{
    mixed * neighbors = ({});

    int sz_a = sizeof(mze), sz_b = sizeof(mze[0]);

    if (a[0] > 0) {
            neighbors += ({({a[0] - 1, a[1]})});
    }
    if (a[1] > 0) {
            neighbors += ({({a[0], a[1] - 1})});
    }
    if (a[0] < sz_a - 1) {
            neighbors += ({({a[0] + 1, a[1]})});
    }
    if (a[1] < sz_b - 1) {
            neighbors += ({({a[0], a[1] + 1})});
    }
    return neighbors;
}

mixed *all_empty_neighbors(mixed *mze, int *a)
{
    mixed * nbrs = all_neighbors(mze, a);

    return filter_array(nbrs, (:!sizeof($2[$1[0]][$1[1]]):), mze);
}


int *random_empty_neighbor(mixed *mze, int *a)
{
    mixed * unj;

    unj = all_empty_neighbors(mze, a);

    if (!sizeof(unj)) {
        return 0;
    }

    return unj[random(sizeof(unj))];
}

int digthrough(mixed *mze, int coord)
{
    int i;

    int sz_a = sizeof(mze), sz_b = sizeof(mze[0]);

    for (i = 0; i < sz_a; i++ )
    {
        connect_points(mze, ({coord, i}), ({coord, i - 1}));
    }
}

/**
 * Simplest "maze", or a non-maze start for dichotomy algorythms.
 */
/* connect_all() */
/* { */
/*     int i, j; */
/*     int *k; */
/*     mixed * u; */

/*     for (i = 0; i < SIZE_A; i++ ) */
/*     { */
/*         for (j = 0; j < SIZE_B; j++ ) */
/*         { */
/*             u = unjoined_neighbors(({i, j})); */
/*             foreach(k in u) { */
/*                 connect_points(({i, j}), k); */
/*             } */
/*         } */
/*     } */
/*  */

/**
 * Bucklog algorythm. "Eldebaro".
 *
 * Modifies passed maze.
 */
bucklog(mixed *mze)
{
    int i, j, k;
    int *randbreaks = ({});
    int randbreak, prevbreak;
    int a;

    int size_a = sizeof(mze), size_b = sizeof(mze[0]);

    for (i = 0; i < size_a; i++ )
    {
        for (k = 0; k < size_b / 4; k++ )
        {
            randbreaks += ({random(size_b) + 1});
        }
        randbreaks += ({size_b + 1});
        randbreaks = sort_array(distinct_array(randbreaks), 1);
        prevbreak = 0;
        randbreak = randbreaks[0];
        randbreaks = randbreaks[1..];
        for (j = 0; j <= size_b; j++ )
        {
            if (j < randbreak) {
                connect_points(mze, ({i, j - 1}), ({i, j}));
            } else {
                a = prevbreak + random(randbreak - prevbreak + 1);
                connect_points(mze, ({i - 1, a}), ({i, a}));
                prevbreak = randbreak;
                randbreak = randbreaks[0];
                randbreaks = randbreaks[1..];
            }
        }
    }
}

/**
 * Non-recursive Backtrack algorithm.
 *
 * All points are connected.
 */
backtrack(mixed *mze)
{
    int size_a = sizeof(mze), size_b = sizeof(mze[0]);

    int *point;

    int *t_pos = ({size_a / 2, size_b / 2});

    mixed * stack = ({t_pos});

    while (sizeof(stack)) {
        do {
            point = random_empty_neighbor(mze, t_pos);
            if (!point) {
                break;
            }
            connect_points(mze, t_pos, point);
            stack += ({ point });
            t_pos = point;
        } while (sizeof(point));
            t_pos = stack[sizeof(stack) - 1];
        stack = stack[0..(sizeof(stack) - 2)];
    }
}

simple_render(mixed *mze)
{
    int i, j;
    int sz_a = sizeof(mze), sz_b = sizeof(mze[0]);

    mixed * p_m = allocate(sz_a * 2 + 1, ({}));
    string buff;

    for (i = 0; i < sz_a * 2 + 1; i++ )
    {
        p_m[i] = allocate(sz_b * 2 + 1, " ");
    }

    for (i = 0; i < sz_a; i++ )
    {
        for (j = 0; j < sz_b; j++ )
        {

            p_m[i * 2 + 1][j * 2 + 1] = sizeof(mze[i][j]) ? ("▓") : (" ");

            if (has_point(({i - 1, j}), mze[i][j])) {
                p_m[i * 2][j * 2 + 1] = "▓";
            }

            /* if (has_point(({i + 1, j}), mze[i][j])) { */
            /*     p_m[i * 2 + 2][j * 2 + 1] = " "; */
            /* } */

            if (has_point(({i, j - 1}), mze[i][j])) {
                p_m[i * 2 + 1][j * 2] = "▓";
            }

            /* if (has_point(({i, j + 1}), mze[i][j])) { */
            /*     p_m[i * 2 + 1][j * 2 + 2] = " "; */
            /* } */
        }
    }

    for (i = 0; i < sz_a * 2 + 1; i++ )
    {
        buff = "";
        for (j = 0; j < sz_b * 2 + 1; j++ )
        {
            buff += p_m[i][j];
        }
        write(buff);
    }
}

string example(int x, int y, string ss)
{
    mixed * maze = alloc_maze(y, x);

    if (!stringp(ss)) {
        set_seed(make_entropy());
    } else {
        set_seed(ss);
    }
    backtrack(maze);
    simple_render(maze);
    return seed;
}

remove()
{
    destruct(this_object());
}
