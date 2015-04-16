# Presenting WaI! (Where am I?) #

Wai is a mini GPS navigator (just for map viewing at the moment), and th idea is to have a GPL3 GPS navigator that can be used with the Openmoko with no need for an Internet connection: when you are on the road you have no Internet... and even if you connect throught your mobile provider, Openmoko only have GPRS.. too slow for Tango to work I guess.

![![](http://waiwhereami.googlecode.com/svn/trunk/screenshots/chanchi.png)](http://waiwhereami.googlecode.com/svn/trunk/screenshots/chanchi.png)

## Wiki ##

this is a partial list of the more important pages on this Wiki:

  * [Screenshots](Screenshots.md)
  * [WaiFormat](WaiFormat.md)
  * [HowtoUse](HowtoUse.md)

## WaI! How ##

So my solution takes an OpenStreetMap OSM file and converts it to a custom fast access format (esentially a KD Tree index, and tight data files). And then the viewer draws it as fast as possible. To make it even faster instead of old-fassioned file access methods, I use mmaped files. This is supposed to be faster (and it is), and removes lots of overhead, cache tricks and all that and leaves the hard work to the kernel... anyway it will do it finally.

Everything uses Qt4, and just some numbers on my Dual Core @ 1500 MHz on a ~ 380x400 area:

  * Drawing my neighbourhood, quite populated: 30 ms.
  * Drawing a friends neighbourhood, less populated: 1 ms.
  * Drawing all Madrid area: 900 ms.


Just now there are some tricks, but not 'the big dumb idea' of not drawing everything as you move, just the changed areas, so big improvements are on the way. Also it is prepared to support several layers, for example one for big objects when you are looking from far, and street level when closer. It just needs the exporter to split data on preselected filters. Actually there is lot of infraestructure on the code to support this.

Just now the converter is about 3000 lines of code, and the viewer 4700, so it is quite small.

## Future ##

Next steps:


  * Make it work with layers, so we can optimize access depending on the zoom level.
  * Make it work on the Openmoko: should be just a thing of compiling it, and (I hope not) solve memory alignment issues with the mmaping stuff.
  * Make it work with the GPS
  * Solve routes!


Last step is optional by the moment, as I think this is maybe the biggest problem here to be able to do it fast. anyway if succeeded then the navigator will be 100 functional... and new goals should be established.

## More ##

There is also a blog at http://blog.monasteriomono.org. Important news will be featured on both sites, but to stay with the development improvements the blog may be more updated.

## About the name ##

The name sound exactly as the spanish word 'Guay' that is similar to 'Cool'. Actually there is a pun intended with the word Way, and in the last moment I found funny adding the exclamation and question marks, so its like 'Cool! Where the Fk am I?'