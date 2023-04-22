function downloadFireflies() {
    window.location="FireFlies.ino";
    window.downloadFireflies
}

function onStartedDownload(id) {
    console.log(`Started downloading: ${id}`);
  }
  
  function onFailed(error) {
    console.log(`Download failed: ${error}`);
  }

function dl(){

    

    var durl="FireFlies.ino";

    var downloading = chrome.downloads.download({
        url : durl, filename : 'FireFlies.ino', conflictAction : 'uniquify'
    });
    downloading.then(onStartedDownload, onFailed);
}