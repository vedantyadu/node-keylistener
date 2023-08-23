const { execFile } = require('child_process')

function keyListener(callback) {
  const child = execFile('./bin/keylistener.exe')
  child.stdout.on('data', (data) => {
    const data_split = data.toString().split(' ')
    const key_state = {
      key: data_split[0],
      state: data_split[1].replace('\r\n', '')
    }
    callback(key_state)
  })
  return child
}

module.exports = {keyListener}
