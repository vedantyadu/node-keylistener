
const {keyListener} = require('../index')

const listener = keyListener((data) => {
  if (data.key == 'ESCAPE') {
    listener.kill()
  }
  console.log(data)
})
