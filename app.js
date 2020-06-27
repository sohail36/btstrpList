const btn=document.querySelector('.add');
var parent=document.querySelector('.list-group');
btn.addEventListener('click',(e)=>{
    e.preventDefault();
    const item=document.querySelector('input');
    if(item.value.length==0){
        alert("Item cannot be EMPTY");
        return;
    }
    
    addItem(item.value);
    item.value="";
});

function delItem(e){
    var item_del=e.target.parentElement.parentElement;
    if(e.target.classList.contains('btn-success'))
        item_del.classList.toggle('decorate');
    else{
        item_del.classList.add('animae');
        setTimeout(() => {
            item_del.remove();
        }, 1000);
    }
}



function addItem(item){

    var div=document.createElement('div');
    div.classList.add('btn-group');
    div.innerHTML=`
        <a role="button" class="btn btn-success btn-sm minor" href="#"><span class="fa fa-check rightmark"></span></a>
        <a href="#" role="button" class="btn btn-danger minor btn-sm"><span class="fa fa-trash trash"></span></a>
    `
    div.addEventListener('click',delItem); 
    var li=document.createElement('li');
    li.innerText=`${item}`;
    li.classList.add('list-group-item');
    li.append(div);
    parent.append(li);
}