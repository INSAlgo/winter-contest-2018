from math import atan2, pi

def main():
    N = int(input())
    coordinates = [tuple(map(int, input().split())) for _ in range(N)]

    # Conversion of coordinates to couples of angles
    angles = [(atan2(t[1], t[0]), atan2(t[3], t[2])) for t in coordinates]

    # Ordering couples in direct order, then storing first angle and difference
    ang_segments = []
    for angle in angles:
        if ((angle[0] < angle[1] and angle[1] - angle[0] > pi)
         or (angle[0] > angle[1] and angle[0] - angle[1] < pi)):
            angle = (angle[1], angle[0])
        first = angle[0]
        diff = ((angle[1] - angle[0]) if angle[1] >= angle[0]
                else angle[1] + 2*pi - angle[0])
        ang_segments.append((first, diff))

    # Projecting angles on the same quarter of the circle (interval [0, pi/2])
    ang_segments = [(ang % (pi/2), diff) for (ang, diff) in ang_segments]

    # Dividing segments which exceed angle pi/2
    # Storing start and end angles (no more diff)
    ang_div = []
    for (ang, diff) in ang_segments:
        if diff >= pi / 2: # a segment occupies a full quarter
            return 0
        if ang + diff < pi / 2:
            ang_div.append((ang, ang + diff))
        else:
            ang_div.append((ang, pi / 2))
            ang_div.append((0, diff + ang - pi / 2))

    # Sorting segments
    ang_div.sort()

    # Finally calculating the proportion of range [0, pi/2] which is "free"
    proportion = 0
    prev_max = 0
    for (a_start, a_end) in ang_div:
        if a_start > prev_max:
            proportion += a_start - prev_max
        if a_end > prev_max:
            prev_max = a_end
    proportion += pi/2 - prev_max

    return 2 * proportion / pi
    

print("%0.2f" % main())