# Introduction #

Wai Meta Files stores basic information about layers that will be used on the `wai` viewer.

The file stores one line per layer, and it has two space separated fields: the path to the map, and the zoom level applicable. The zoom level is specified as `min-max` where min and max are the minimum and maximum zoom levels applicable respectively. Any of both can be omited of be 0, which means that this restriction (min or max) should not be applied. The zoom level is experimental, but relates to the area viewed: more area bigger the number.

The following is an example from the `preparemaps.sh` script:

```
/tmp/layers/areas -
/tmp/layers/baseareas -20000
/tmp/layers/roads -
/tmp/layers/basestreets -10000
/tmp/layers/basestreets2 -10000
```