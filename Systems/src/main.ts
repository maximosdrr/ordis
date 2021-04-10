//

// server.on("ready", () => {
//   console.log("Servidor Inicado");
// });

// server.on("clientConnected", () => {
//   console.log("Novo cliente conectado");
// });

import app from "./app";

const port = 3001;

app.server.listen(port, () => {
  console.log(`server running in" + ${port}`);
});
