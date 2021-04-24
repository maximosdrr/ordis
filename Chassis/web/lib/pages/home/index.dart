import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:web/pages/home/tabs/devices/index.dart';
import 'package:web/store/root.dart';

class Home extends StatefulWidget {
  Home({Key key}) : super(key: key);

  @override
  _HomeState createState() => _HomeState();
}

class _HomeState extends State<Home> {
  final store = AppState();
  int selectedIndex = 0;

  final List<Widget> tabs = [DevicesPage()];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Container(
        child: Row(
          children: [
            NavigationRail(
              extended: true,
              destinations: [
                NavigationRailDestination(
                  icon: Icon(Icons.favorite_border),
                  selectedIcon: Icon(Icons.favorite),
                  label: Text('Devices'),
                ),
                NavigationRailDestination(
                  icon: Icon(Icons.favorite_border),
                  selectedIcon: Icon(Icons.favorite),
                  label: Text('Devices'),
                ),
              ],
              selectedIndex: selectedIndex,
              onDestinationSelected: (int i) {
                setState(() {
                  selectedIndex = i;
                });
              },
            ),
            tabs[selectedIndex],
          ],
        ),
      ),
    );
  }
}
