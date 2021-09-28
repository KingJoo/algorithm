#include<cstdio>
int tc, t, i, x1, y1, x2, y2, n, a, b, in, bw, out;

int main() {
    scanf("%d", &tc);
    for (t = 1; t <= tc; t++) {
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &n);
        in = bw = out = 0;
        for (i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
            if (a<x2 && a>x1 && b<y2 && b>y1)   in++;
            else if (((a == x1 || a == x2) && b <= y2 && b >= y1) || ((b == y1 || b == y2) && a <= x2 && a >= x1))  bw++;
            else	out++;
        }
        printf("#%d %d %d %d\n", t, in, bw, out);
    }
    return 0;
}
