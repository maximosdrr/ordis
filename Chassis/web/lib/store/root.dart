import 'package:mobx/mobx.dart';

part 'root.g.dart';

class AppState = _AppStateBase with _$AppState;

abstract class _AppStateBase with Store {
  @observable
  int counter = 0;

  @action
  increment() {
    return counter++;
  }
}
