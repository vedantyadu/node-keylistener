
const {keyListener} = require('../index')

const listener = keyListener((data) => {
  console.log(data)
  if (data.key == 'ESCAPE') {
    listener.kill()
  }
})