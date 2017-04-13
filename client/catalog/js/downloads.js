
class DownloadStatus {
  
  constructor(name, tooltip) {
    this.dlDom = $('#download-template').clone().attr('id','');
    $('#downloads').append(this.dlDom);
    this.dlDom.find('.download-name').text(name).attr('title', tooltip);
    this.dlDom.find('.progres-bar').css('width', '5%');
    this.dlDom.find('.download-status').text("Initiating");
    var scope = this;
    this.dlDom.find('.close').click(function(){
      scope.close();
    });
  }
  
  focus() {
    $('#downloads-tab a').click();
    $.scrollTo('#downloads');
  }
  
  setProgress(percent) {
    this.dlDom.find('.progress-bar').css('width', percent + '%');
    return this;
  }
  
  makeSolid(){
    this.dlDom.find('.progress-bar').removeClass('progress-bar-striped').removeClass('active');
    return this;
  }
  
  makeInactive(){
    this.dlDom.find('.progress-bar').removeClass('active');
    return this;
  }
  
  setStatus(status){
    this.dlDom.find('.download-status').text(status);
    return this;
  }
  
  setFailed() {
    this.dlDom.removeClass('panel-default').addClass('panel-danger');
    this.dlDom.find('.progress-bar').removeClass('active').addClass('progress-bar-danger');
    return this;
  }
  
  close() {
    this.dlDom.remove();
  }
  
}
