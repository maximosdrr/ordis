import 'package:flutter/material.dart';

class DevicesPage extends StatelessWidget {
  const DevicesPage({Key key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Expanded(
      child: Column(
        children: [
          Center(
            child: Text("Devices"),
          ),
        ],
      ),
    );
  }
}
