import 'package:flutter/material.dart';
import 'package:web/routes.dart';
import 'package:web/theme/index.dart';

class OrdisWebChassis extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Ordis Control Panel',
      theme: AppTheme.mainTheme,
      onGenerateRoute: AppRouter.generateRoute,
      initialRoute: '/',
    );
  }
}
