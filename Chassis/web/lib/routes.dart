import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:web/pages/home/index.dart';

class AppRouter {
  static Route<dynamic> generateRoute(RouteSettings settings) {
    final dynamic args = settings.arguments;

    switch (settings.name) {
      case '/':
        return MaterialPageRoute(builder: (context) => Home());
      default:
        return MaterialPageRoute(
          builder: (context) => Scaffold(
            body: Center(
              child: Text("No route for ${settings.name}"),
            ),
          ),
        );
    }
  }
}
