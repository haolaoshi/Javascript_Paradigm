/*
**
* Javascript 做抽象接口，列出的是BSCC必须实现的基本话务功能,不涉及实现
* 各平台对接时，只要实现这些方法就可以完成话务功能基本对接
*
* Javascript 没有内置接口语法，接口的保证需要靠你我共同遵守约定：
* 1,
 */
//(1)Comments to declare interface , improving reusable and documentation

var PhonebarInterface = function(id,method,action){

};

PhonebarInterface.prototype.add = function(child){

};

PhonebarInterface.prototype.remove = function(child){

};

PhonebarInterface.prototype.getChild = function (index) {
    
};

PhonebarInterface.prototype.save = function(){

};

//带属性检查的interface
var CompositeForm = function(id,method,action){
    this.implementsInterfaces = ['Composite','FormItem'];
};

function addItem(formInterface) {
    if(!implements(formInterface,'Composite','FormItem')){
        throw new Error("Object does not implements required interface !");
    }
}
function implements(object){
    for(var i = 1; i < arguments.length; i++){
        var interfaceName = arguments[i];
        var interfaceFound = false;

        for(var j = 0 ; j < object.implementsInterfaces.length; j++){
            if(object.implementsInterfaces[j] == interfaceName ){
                interfaceFound = true;
                break;
            }
        }

        if(!interfaceFound){
            return false;
        }
    }
    return true;
}
//DUCK TYPEING
//interface
var Compose = new Interface('Compose',['add','remove','getChild']);
var Form = new Interface('Form',['saved']);
//class
var Compositor = function (id,method,action) {

};
function addWritor(obj) {
    Interface.ensureImplements(obj,Compose,Form);
}


//Interface Helper class --- ensureImplements  : explicit checking of method.
var Interface = function (name, methods) {
    if(arguments.length != 2){
        throw new Error("Interface Class Called with " + arguments.length + " arguments," +
            "but expect exactly 2 .");
    }
    this.name = name ;
    this.methods = [];
    for(var i = 0 , len = methods.length; i < len; i++ ){
        if(typeof methods[j] !== 'string'){
            throw new Error("Interface constructor expects methods names to be passed in a  string ");
        }
        this.methods.push(methods[i]);
    }
};
//constructor checking
Interface.ensureImplements = function (object) {
    if(arguments.length < 2){
        throw  new Error("Function Interfae.ensureImplements called with " + arguments.length + " " +
            "arguments , but expected at least 2.");
    }
    for(var i = 1,len = arguments.length; i < len ; i++){
        var interface = arguments[i];
        if(interface.constructor != Interface ){
            throw new Error("Functon Interface.ensureIMplements expects two and aboue to be instance of " +
                "Interface .");
        }
        for(var j = 0 , methodLen = interface.methods.length; j < methodLen; j++){
            var method = interface.methods[j];
            if(!object[method] || typeof object[method] !== 'function'){
                throw new Error("Function Interface.sunsureImpelments :  object does not implement the" +
                    " " + interface + " interface , Method " + method + " was not found .");
            }
        }
    }
}
/******************************************************************************************/
//Full Exposed
var Book = function(sibn, title,author){
    if(isbn == unefined) throw new Error('Book constructor require a isbn.');
    this.isbn  = isbn;
    this.title = title||'No title specified.';
    this.author = author || 'No Author specified.';
}
Book.prototype.display = function () {

};
/**
 * Convention : a underscore means private  members
 * ***********************
 * IMPROVED II: use
 * @type {Interface}
 */
var Publication = new Interface('Publication',['getIsbn','setIsbn','getTitle','setTitle','getAuthor','display']);
var Book = function(newIsbn,newTitle,newAuthor){
    //private members
    var isbn,title,author;
    //private method
    function checkIsbn(isbn){
    }
    //Privilege
    this.getIsbn = function () {
        return isbn;
    };
    this.setIsbn = function (newIsbn) {
        if(!checkIsbn(newIsbn)) throw new Error('require a isbn.');
        isbn = newIsbn;
    };

    this.getTitle = function () {
        return title;
    };
    this.setTitle = function (newTitle) {
        title = newTitle || 'No title offered.';
    };

    this.getAuthor = function () {
        return author;
    };
    this.setAuthor = function (newAuthor) {
        author = newAuthor || 'No Author offered.';
    };

    this.setIsbn(newIsbn);
    this.setTitle(newTitle);
    this.setAuthor(newAuthor);
};
//public , no privilege
Book.prototype = {
    display   : function () {

    }
};
/****************STATIC METHOD PATTERN ***********************/
//book class with static attr and method
var Book = (function () {
    //private static attr
    var num = 9;
    //private static method
    function checkIsbn(isbn) {
    }
    //return constructor
    return function (newIsbn , newTitle,newAuthor) {
        //Private attr
        var isbn,title,author;
        //Privileage
        this.getIsbn = function () {
            return isbn;
        };
        this.setIsbn = function (newIsbn) {
            if(!checkIsbn(newIsbn)) throw new Error('require a solid isbn.');
            isbn = newIsbn;
        };
        this.getTitle = function () {
            return title;
        };
        this.setTitle = function (newTitle) {
            title = newTitle || 'No Title offered.';
        };
        this.setAuthor = function (newAuthor) {
            author = newAuthor || 'No Author offered.';
        };
        this.getAuthor = function () {
            return author;
        };
        //Constructor code
        num++;//Keep track how many obj generate
        if(num > 50) throw new Error('Cannot create obj more than 50.');

        this.setIsbn(newIsbn);
        this.setTitle(newTitle);
        this.setAuthor(newAuthor);
    }
})();


//1.CLASSICAL INHERITANCE -------------------------------------
function Person(name){
    this.name = name;
}
Person.prototype.getName = function(){
    return this.name;
};
/**
 Usage :
 var reader = new Persion("John Smith");
 reader.getName();
 ***/

//2.Prototype Chain
function Author(name,books) {
	Person.call(this,name);
	this.books = books;
}
Author.prototype = new Person();//set up prototype chain
Author.prototype.constructor = Author;  //Set constructor attribute
Author.prototype.getBooks = function () {
	return this.books;
}
// extends function
function extend(subClass,superClass){
	var F = function () {	};  // add to protochain to prevent superClass large instance produce.
	F.prototype = superClass.prototype;
	subClass.prototype = new F();
	subClass.prototype.constructor = subClass;
}
/**
 function Person(name){
 		this.name = naem;
 }
 Person.prototype.getName(){
    return this.name;
 }
 function Author(name,books){
 		Person.call(this,name);
 		this.books = books;
 }
 extend(Author,Person);
 Author.prototype.getBooks = function(){
 		return this.books;
 };
 ***/

// extends function
function extend(subClass,superClass){
	var F = function () {	};  // add to protochain to prevent superClass large instance produce.
	F.prototype = superClass.prototype;
	subClass.prototype = new F();
	subClass.prototype.constructor = subClass;

	subClass.superClass = superClass.prototype;
	if(superClass.prototype.constructor  == Object.prototype.constructor ){
		superClass.prototype.constructor = superClass;
	}
}

function Author(name,books) {
	Author.superClass.constructor.call(this,name);
	this.books = books;
}
extend(Author,Person);
Author.prototype.getName = function(){
	var name = Author.superClass.getName().call(this);
	return name + " of Author " + this.getBooks() + " 's";
}


/***********************  Prototype Inheritance*************************************
 *
 * @type {{name: string, getName: Person.getName}}
 */
var Person = {
	name : 'default Name',
	getName : function(){
		return this.name;
	}
};
var Author = clone(Person);
Author.books = [];
Author.getBooks = function(){
	return this.books;
}

var author = [];
author[0] = clone(Author);
author[0].name = 'a';
author[0].books = 'b';


//Asymentry
var anothr = clone(Author);
alert(anothr.name); // point to persion 's name
anothr.name = 'newName';
alert(anothr.name);//newName;

//带有内部子对象的创建实践
var CompoundObject = {};
CompoundObject.string1 = 'default value';
CompoundObject.createObjectChild = function(){
	return {
		bool : true,
		num : false
	}
};

CompoundObject.childObj = CompoundObject.createObjectChild();

//use
var comObjClone = clone(CompoundObject);
comObjClone.childObj = CompoundObject.createObjectChild();//let subclass known thre structure and default value;
comObjClone.num = 5;

//MIXIN Paradigm
var Mixin = function(){};
Mixin.prototype={
	serialize : function () {
		var outputs = [];
		for(var key in this){
			outputs.push(key + ' : ' + this[key]);
		}
		return outputs.join(',');
	}
};

argument(Author,Mixin);
var author = new Author('John',['Javascript Design Pattern']);
var jsonAuthor = author.serialize();

function argument(recivingClass,givingClass) {
	for(methodName in givingClass.prototype){
		if(!recivingClass.prototype[methodName]){
			recivingClass.prototype[methodName] = givingClass.prototype[methodName];
		}
	}
}

//improvable version : specified methods
function argument(recivingClass,givingClass) {
	if(arguments[2]){
		for(var i = 2,len = arguments.length; i<len; i++){
			recivingClass.prototype[arguments[i]] = givingClass.prototype[arguments[i]];
		}
	}else{
	//all methods
		for(methodName in givingClass.prototype){
			if(!recivingClass.prototype[methodName]){
				recivingClass.prototype[methodName] = givingClass.prototype[methodName];
			}
		}
	}
}
//now ,we can call  argument only we need, to prevent code duplicate
argument(Author,Mixin,'serialize');


/*************** EDIT - IN - PLACE *********************/
/** (1) CLASSICAL INHERITANCE ***/
function EditInPlaceField(id,parent,value) {
	this.id = id;
	this.value = value || 'No value default';
	this.parentElemtnt = parent;

	this.createElement(this.id);
	this.attachEvents();
};
EditInPlaceField.prototype = {
	createElement : function (id) {
		this.containerElement = document.createElement('div');
		this.parentElemtnt.context.appendChild(this.containerElement);

		this.staticElement = document.createElement('span');
		this.containerElement.appendChild(this.staticElement);
		this.staticElement.innerHTML  = this.value;

		this.fieldElement = document.createElement('input');
		this.fieldElement.type = 'text';
		this.fieldElement.value = this.value;
		this.containerElement.appendChild(this.fieldElement);

		this.saveBtn = document.createElement('input');
		this.saveBtn.type = 'button';
		this.saveBtn.value = 'Save';
		this.containerElement.appendChild(this.saveBtn);

		this.cancelBtn = document.createElement('input');
		this.cancelBtn.type = 'button';
		this.cancelBtn.value = 'Cancel';
		this.containerElement.appendChild(this.cancelBtn);

		this.convertToText();
	},
	attachEvents	:	function () {
		var that = this;
		this.addEvent(this.staticElement,'click',function () {
			that.convertToEditable();
		});
		this.addEvent(this.saveBtn,'click',function () {
			that.save();
		});
		this.addEvent(this.cancelBtn,'click',function () {
			that.cancel();
		});
	},
	addEvent : function(element, type, handler) {
		if (element.addEventListener) {
			//事件类型、需要执行的函数、是否捕捉
			element.addEventListener(type, handler, false);
		} else if (element.attachEvent) {
			element.attachEvent('on' + type, function() {
				handler.call(element);
			});
		} else {
			element['on' + type] = handler;
		}
	},
	convertToEditable	:	function () {
		this.staticElement.style.display = 'none';
		this.fieldElement.style.display = 'inline';
		this.saveBtn.style.display = 'inline';
		this.cancelBtn.style.display = 'inline';
		this.setValue(this.value);
	},
	save	:	function(){
		this.value = this.getValue();
		var that = this;
		var callback = {
			success	:	function () {
				that.converToText();
			},
			failure : function () {
				alert('Error saving value.')
			}
		};
		//ajaxRequext('Get','save.php?id=' + this.id + '&value=' + this.value , callback);
		alert('ajaxRequext ... ');
	},
	cancel : function () {
		this.convertToText();
	},
	convertToText	:	function () {
		this.staticElement.style.display = 'inline';
		this.fieldElement.style.display = 'none';
		this.saveBtn.style.display = 'none';
		this.cancelBtn.style.display = 'none';
		this.setValue(this.value);
	},
	setValue	:	function(v){
		this.fieldElement.value = v;
		this.staticElement.innerHTML = v;
	},
	getValue 	: function () {
		return this.fieldElement.value;
	}
};

var titleClassical = new EditInPlaceField('titleClassical',$('doc'),'Title here');
//var currentText = titleClassical.getValue();


function EditInPlaceArea(id,parent,value) {
	EditInPlaceArea.prototype.constructor.call(this,id,parent,value);
};
extend(EditInPlaceArea,EditInPlaceField);
//overide certain method
EditInPlaceArea.prototype.createElement = function(id){
	this.containerElement = document.createElement('div');
	this.parentElemtnt.context.appendChild(this.containerElement);

	this.staticElement = document.createElement('p');
	this.containerElement.appendChild(this.staticElement);
	this.staticElement.innerHTML  = this.value;

	this.fieldElement = document.createElement('textarea');
	this.fieldElement.type = 'text';
	this.fieldElement.value = this.value;
	this.containerElement.appendChild(this.fieldElement);

	this.saveBtn = document.createElement('input');
	this.saveBtn.type = 'button';
	this.saveBtn.value = 'Save';
	this.containerElement.appendChild(this.saveBtn);

	this.cancelBtn = document.createElement('input');
	this.cancelBtn.type = 'button';
	this.cancelBtn.value = 'Cancel';
	this.containerElement.appendChild(this.cancelBtn);

	this.convertToText();
};
EditInPlaceArea.prototype.convertToEditable = function () {
	this.staticElement.style.display = 'none';
	this.fieldElement.style.display = 'block';
	this.saveBtn.style.display = 'inline';
	this.cancelBtn.style.display = 'inline';
	this.setValue(this.value);
};
EditInPlaceArea.prototype.convertToText = function () {
	this.staticElement.style.display = 'block';
	this.fieldElement.style.display = 'none';
	this.saveBtn.style.display = 'none';
	this.cancelBtn.style.display = 'none';
	this.setValue(this.value);
};

///////////////////////PROTOTYPE INHERITANCE=======================

var EditInPlaceField = {
	configure : function (id,parent,value) {
		this.id = id;
		this.value = value || 'defalut value';
		this.parentElement = parent;

		this.createElement(this.id);
		this.attachEvents();
	},
	createElements	:	function (id) {
		this.containerElement = document.createElement('div');
		this.parentElemtnt.context.appendChild(this.containerElement);

		this.staticElement = document.createElement('span');
		this.containerElement.appendChild(this.staticElement);
		this.staticElement.innerHTML  = this.value;

		this.fieldElement = document.createElement('input');
		this.fieldElement.type = 'text';
		this.fieldElement.value = this.value;
		this.containerElement.appendChild(this.fieldElement);

		this.saveBtn = document.createElement('input');
		this.saveBtn.type = 'button';
		this.saveBtn.value = 'Save';
		this.containerElement.appendChild(this.saveBtn);

		this.cancelBtn = document.createElement('input');
		this.cancelBtn.type = 'button';
		this.cancelBtn.value = 'Cancel';
		this.containerElement.appendChild(this.cancelBtn);

		this.convertToText();
	},
	attachEvents : function () {

	},
	convertToEditable	:	function () {

	},
	save		:	function () {

	},
	cancel	:	function () {

	},
	convertToText	:	function () {
		
	},
	setValue	:	function () {
		
	},
	getValue	:	function () {
		
	}
};//instead of a Class , this is a Object;

var titlePrototype = clone(EditInPlaceField);
titlePrototype.configure('titlePrototype',$('doc'),'TitleProt');
var EditAreaPrototype = clone(EditInPlaceField);
EditAreaPrototype.prototype.createElements = function (id) {

}


